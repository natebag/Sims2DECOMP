#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ERTQuantize4D (stub_classes.h)
// 2 functions, 208 bytes

// 0x8035EB84 (80 bytes)
// ERTQuantize4D::Deallocate(void)
__attribute__((noreturn))
void ERTQuantize4D::Deallocate(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	3,4104(31)\n"
        "cmpwi	3,0\n"
        "beq	.L_8035EBB8\n"
        "lwz	9,4096(31)\n"
        "mtlr	9\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,4104(31)\n"
        ".L_8035EBB8:\n"
        "li	0,1\n"
        "sth	0,4102(31)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x803604E8 (128 bytes)
// ERTQuantize4D::EVecToFVec(EVec4 &, unsigned short *)
__attribute__((noreturn))
void ERTQuantize4D::EVecToFVec(EVec4 &, unsigned short *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "lis	9,-32702\n"
        "lfs	0,0(4)\n"
        "lfs	11,11928(9)\n"
        "fmuls	0,0,11\n"
        "mr	11,9\n"
        "mr	10,9\n"
        "fctiwz	13,0\n"
        "mr	8,9\n"
        "stfd	13,8(1)\n"
        "lwz	9,12(1)\n"
        "sth	9,0(5)\n"
        "lfs	0,4(4)\n"
        "fmuls	0,0,11\n"
        "fctiwz	12,0\n"
        "stfd	12,8(1)\n"
        "lwz	11,12(1)\n"
        "sth	11,2(5)\n"
        "lfs	0,8(4)\n"
        "fmuls	0,0,11\n"
        "fctiwz	10,0\n"
        "stfd	10,8(1)\n"
        "lwz	10,12(1)\n"
        "sth	10,4(5)\n"
        "lfs	0,12(4)\n"
        "fmuls	0,0,11\n"
        "fctiwz	9,0\n"
        "stfd	9,8(1)\n"
        "lwz	8,12(1)\n"
        "sth	8,6(5)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

