#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for SpriteSlot (stub_classes.h)
// 1 functions, 160 bytes

// 0x80143398 (160 bytes)
// SpriteSlot::ActivateForTicks(int)
__attribute__((noreturn))
void SpriteSlot::ActivateForTicks(int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr	30,4\n"
        "lwz	0,16(31)\n"
        "cmpwi	0,0\n"
        "beq	.L_80143404\n"
        "lwz	0,72(31)\n"
        "andi.	9,0,16\n"
        "bne	.L_80143404\n"
        "lwz	0,24(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_80143404\n"
        "lwz	0,28(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_80143404\n"
        "lwz	11,100(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80143404\n"
        "lwz	9,4(11)\n"
        "lha	3,872(9)\n"
        "lwz	0,876(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80143404:\n"
        "li	0,0\n"
        "stw	30,16(31)\n"
        "stw	0,56(31)\n"
        "cmpwi	30,-1\n"
        "bne	.L_80143420\n"
        "stw	0,20(31)\n"
        "b	.L_80143424\n"
        ".L_80143420:\n"
        "stw	30,20(31)\n"
        ".L_80143424:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

