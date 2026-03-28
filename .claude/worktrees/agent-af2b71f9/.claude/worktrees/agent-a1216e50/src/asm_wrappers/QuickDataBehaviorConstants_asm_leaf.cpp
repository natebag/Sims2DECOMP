#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for QuickDataBehaviorConstants (stub_classes.h)
// 2 functions, 204 bytes

// 0x8015A070 (112 bytes)
// QuickDataBehaviorConstants::QueryInterface(unsigned int, void **)
__attribute__((noreturn))
void QuickDataBehaviorConstants::QueryInterface(unsigned int, void **) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,5\n"
        "beq	.L_8015A0C8\n"
        "cmpwi	4,1\n"
        "beq	.L_8015A0A4\n"
        "lis	0,-5160\n"
        "ori	0,0,51892\n"
        "cmpw	4,0\n"
        "bne	.L_8015A0C8\n"
        ".L_8015A0A4:\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	31,0(30)\n"
        "li	3,1\n"
        "b	.L_8015A0CC\n"
        ".L_8015A0C8:\n"
        "li	3,0\n"
        ".L_8015A0CC:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8015A0F4 (92 bytes)
// QuickDataBehaviorConstants::Release(void)
__attribute__((noreturn))
void QuickDataBehaviorConstants::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,28(11)\n"
        "addi	3,9,-1\n"
        "stw	3,28(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_8015A140\n"
        "cmpwi	11,0\n"
        "beq	.L_8015A13C\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,112(9)\n"
        "lwz	0,116(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8015A13C:\n"
        "li	3,0\n"
        ".L_8015A140:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

