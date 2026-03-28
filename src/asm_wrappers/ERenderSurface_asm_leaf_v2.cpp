#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ERenderSurface (stub_classes.h)
// 1 functions, 116 bytes

// 0x80364EE8 (116 bytes)
// ERenderSurface::GetOutputRect(TRect<float> &)
__attribute__((noreturn))
void ERenderSurface::GetOutputRect(TRect<float> &) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "lwz	9,0(3)\n"
        "lwz	11,4(3)\n"
        "lis	0,17200\n"
        "addi	9,9,-1\n"
        "mr	8,10\n"
        "xoris	9,9,32768\n"
        "addi	11,11,-1\n"
        "stw	9,12(1)\n"
        "xoris	11,11,32768\n"
        "lis	7,-32702\n"
        "lis	9,-32702\n"
        "stw	0,8(1)\n"
        "lfd	12,12552(7)\n"
        "lfd	13,8(1)\n"
        "stw	11,12(1)\n"
        "lfs	11,12560(9)\n"
        "fsub	13,13,12\n"
        "stw	0,8(1)\n"
        "frsp	13,13\n"
        "stfs	11,4(4)\n"
        "lfd	0,8(1)\n"
        "stfs	13,8(4)\n"
        "fsub	0,0,12\n"
        "stfs	11,0(4)\n"
        "frsp	0,0\n"
        "stfs	0,12(4)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

