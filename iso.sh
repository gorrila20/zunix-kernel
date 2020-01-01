#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/zUNIX.kernel isodir/boot/zUNIX.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "The zUNIX Kernel ver 0.0.1" {
	multiboot /boot/zUNIX.kernel
}
EOF
grub-mkrescue -o zunix.iso isodir
