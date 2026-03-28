#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for SmartDataFactory (stub_classes.h)
// 2 functions, 204 bytes

// 0x8015CB98 (112 bytes)
// SmartDataFactory::QueryInterface(unsigned int, void **)
__attribute__((noreturn))
void SmartDataFactory::QueryInterface(unsigned int, void **) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,5\n"
        "beq	.L_8015CBF0\n"
        "cmpwi	4,1\n"
        "beq	.L_8015CBCC\n"
        "lis	0,3011\n"
        "ori	0,0,32104\n"
        "cmpw	4,0\n"
        "bne	.L_8015CBF0\n"
        ".L_8015CBCC:\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	31,0(30)\n"
        "li	3,1\n"
        "b	.L_8015CBF4\n"
        ".L_8015CBF0:\n"
        "li	3,0\n"
        ".L_8015CBF4:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8015CC1C (92 bytes)
// SmartDataFactory::Release(void)
__attribute__((noreturn))
void SmartDataFactory::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,20(11)\n"
        "addi	3,9,-1\n"
        "stw	3,20(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_8015CC68\n"
        "cmpwi	11,0\n"
        "beq	.L_8015CC64\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,56(9)\n"
        "lwz	0,60(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8015CC64:\n"
        "li	3,0\n"
        ".L_8015CC68:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

