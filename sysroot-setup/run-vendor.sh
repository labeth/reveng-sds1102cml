#!/bin/bash
# run-vendor.sh — run the REAL Siglent SDS1000_arm.app under qemu-arm against our
# Go device-model sim (sim/fpga via the simd daemon), capturing the full /dev/Gpmc
# register access sequence to tmp/run/reglog.txt.
#
# Pieces:
#   - simd            host Go daemon wrapping sim/fpga.FPGA over a Unix socket
#   - devshim.so      armel LD_PRELOAD shim: /dev/Gpmc ioctls -> simd, fb/key/wdog stubs
#   - tmp/root        chroot rootfs with the app at /usr/bin/siglent/ and the armel libs
#
# Usage: tmp/run/run-vendor.sh [seconds]   (default 30s timeout)
set -u
REPO=/mnt/c/Users/henri/Documents/ws/open-sds1102cml
RUN=$REPO/tmp/run
ROOT=$REPO/tmp/root
SECS=${1:-30}
# abstract-namespace socket: crosses the chroot boundary, works on WSL DrvFs
SOCK=@simfpga
REGLOG=$RUN/reglog.txt
FB=$RUN/fb.raw
SHIMLOG=$RUN/shim.log
APPLOG=$RUN/app.log

echo "== building simd (host) and devshim.so (armel) =="
( cd "$REPO/sim" && go build -o "$RUN/simd" ./cmd/simd/ ) || { echo "simd build failed"; exit 1; }
arm-linux-gnueabi-gcc -shared -fPIC -O2 -U_FORTIFY_SOURCE \
    -o "$RUN/devshim.so" "$REPO/sim/preload/devshim.c" -ldl -lpthread || { echo "shim build failed"; exit 1; }

echo "== refreshing the chroot rootfs =="
# app + bitstream + shim go inside the rootfs (chroot can't see outside it)
cp "$REPO/tmp/extracted/SDS1000_arm.app" "$ROOT/usr/bin/siglent/"
cp "$REPO/tmp/extracted/sds1000_fpga.rbf" "$ROOT/usr/bin/siglent/fpga/" 2>/dev/null
cp "$REPO/tmp/extracted/siglentlib.sh" "$ROOT/usr/lib/"
cp "$RUN/devshim.so" "$ROOT/devshim.so"
cp "$(command -v qemu-arm-static)" "$ROOT/usr/bin/qemu-arm-static"
mkdir -p "$ROOT/tmp"

# Essential /dev nodes the app + shim need (the chroot /dev is otherwise empty).
# Created with sudo since mknod needs CAP_MKNOD; harmless if they already exist.
echo a | sudo -S sh -c "
  mkdir -p '$ROOT/dev'
  [ -e '$ROOT/dev/null' ] || mknod -m 666 '$ROOT/dev/null' c 1 3
  [ -e '$ROOT/dev/zero' ] || mknod -m 666 '$ROOT/dev/zero' c 1 5
  [ -e '$ROOT/dev/random' ] || mknod -m 666 '$ROOT/dev/random' c 1 8
  [ -e '$ROOT/dev/urandom' ] || mknod -m 666 '$ROOT/dev/urandom' c 1 9
  [ -e '$ROOT/dev/tty' ] || mknod -m 666 '$ROOT/dev/tty' c 5 0
  [ -e '$ROOT/dev/tty0' ] || mknod -m 666 '$ROOT/dev/tty0' c 4 0
" 2>/dev/null

echo "== starting simd (abstract socket $SOCK) =="
pkill -f "$RUN/simd" 2>/dev/null; sleep 0.3
"$RUN/simd" -sock "$SOCK" -reglog "$REGLOG" >"$RUN/simd.log" 2>&1 &
SIMD_PID=$!
sleep 0.5
if ! kill -0 $SIMD_PID 2>/dev/null; then echo "simd exited early"; cat "$RUN/simd.log"; exit 1; fi
echo "   simd pid=$SIMD_PID socket=$SOCK"

echo "== running the vendor app under qemu (chroot $ROOT), ${SECS}s guard =="
# Inside the chroot: interpreter /lib/ld-linux.so.3, libs in /lib + /usr/lib, the
# app at /usr/bin/siglent, the shim preloaded, /dev/Gpmc bridged to @simfpga. qemu's
# -E sets the GUEST environment; the abstract socket crosses the chroot boundary.
echo a | sudo -S timeout "$SECS" \
    chroot "$ROOT" /usr/bin/qemu-arm-static \
        -E LD_LIBRARY_PATH=/lib:/usr/lib:/usr/lib/arm-linux-gnueabi \
        -E LD_PRELOAD=/devshim.so \
        -E DEVSIM_TARGET=SDS1000_arm.app \
        -E SIMSOCK=@simfpga \
        -E DEVSIM_FB=/tmp/fb.raw \
        -E DEVSIM_SHIMLOG=/tmp/shim.log \
        -E HOME=/usr/bin/siglent \
        /usr/bin/siglent/SDS1000_arm.app >"$APPLOG" 2>&1
APP_RC=$?
echo "   app exit code: $APP_RC"

# pull the fb + shim log back out of the chroot
cp "$ROOT/tmp/fb.raw" "$FB" 2>/dev/null
cp "$ROOT/tmp/shim.log" "$SHIMLOG" 2>/dev/null

echo "== stopping simd =="
kill -INT $SIMD_PID 2>/dev/null; wait $SIMD_PID 2>/dev/null

# render the framebuffer dump to a PNG so the vendor GUI can be eyeballed
if [ -s "$FB" ]; then
  cat > /tmp/topng.go <<'GO'
package main
import ("image";"image/color";"image/png";"os";"encoding/binary")
func main(){ d,_:=os.ReadFile(os.Args[1]); W,H:=800,480
 img:=image.NewRGBA(image.Rect(0,0,W,H))
 for y:=0;y<H;y++{for x:=0;x<W;x++{ i:=(y*W+x)*2; if i+1>=len(d){continue}
  v:=binary.LittleEndian.Uint16(d[i:i+2])
  img.Set(x,y,color.RGBA{uint8(((v>>11)&0x1f)*255/31),uint8(((v>>5)&0x3f)*255/63),uint8((v&0x1f)*255/31),255}) }}
 f,_:=os.Create(os.Args[2]); defer f.Close(); png.Encode(f,img) }
GO
  ( cd /tmp && go run /tmp/topng.go "$FB" "$RUN/fb.png" ) && echo "   framebuffer PNG -> $RUN/fb.png"
fi

echo "== results =="
echo "  app log : $APPLOG"
echo "  reglog  : $REGLOG  ($(grep -cE '^[RW]' "$REGLOG" 2>/dev/null) accesses)"
echo "  shim log: $SHIMLOG"
echo "  fb dump : $FB  (PNG: $RUN/fb.png)"
echo "  app exit: $APP_RC  (124 = timeout-killed => main loop alive; the expected good outcome)"
echo "---- app.log (filtered) tail ----"
grep -vE 'spi write error|stat error:Value' "$APPLOG" | tail -20
