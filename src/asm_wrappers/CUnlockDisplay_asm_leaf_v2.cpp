#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CUnlockDisplay (stub_classes.h)
// 1 functions, 108 bytes

// 0x800779A0 (108 bytes)
// CUnlockDisplay::destroyObjects(void)
__attribute__((noreturn))
void CUnlockDisplay::destroyObjects(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	11,1124(30)\n"
        "cmpwi	11,0\n"
        "beq	.L_800779F0\n"
        ".L_800779C0:\n"
        "lwz	31,0(11)\n"
        "cmpwi	11,0\n"
        "beq	.L_800779E8\n"
        "lwz	9,132(11)\n"
        "li	4,3\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800779E8:\n"
        "mr.	11,31\n"
        "bne	.L_800779C0\n"
        ".L_800779F0:\n"
        "li	0,0\n"
        "stw	0,1124(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

