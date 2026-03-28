#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for TreeTableQuickData (stub_classes.h)
// 2 functions, 204 bytes

// 0x8015E47C (112 bytes)
// TreeTableQuickData::QueryInterface(unsigned int, void **)
__attribute__((noreturn))
void TreeTableQuickData::QueryInterface(unsigned int, void **) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,5\n"
        "beq	.L_8015E4D4\n"
        "cmpwi	4,1\n"
        "beq	.L_8015E4B0\n"
        "lis	0,27635\n"
        "ori	0,0,8752\n"
        "cmpw	4,0\n"
        "bne	.L_8015E4D4\n"
        ".L_8015E4B0:\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	31,0(30)\n"
        "li	3,1\n"
        "b	.L_8015E4D8\n"
        ".L_8015E4D4:\n"
        "li	3,0\n"
        ".L_8015E4D8:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8015E500 (92 bytes)
// TreeTableQuickData::Release(void)
__attribute__((noreturn))
void TreeTableQuickData::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,32(11)\n"
        "addi	3,9,-1\n"
        "stw	3,32(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_8015E54C\n"
        "cmpwi	11,0\n"
        "beq	.L_8015E548\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,264(9)\n"
        "lwz	0,268(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8015E548:\n"
        "li	3,0\n"
        ".L_8015E54C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

