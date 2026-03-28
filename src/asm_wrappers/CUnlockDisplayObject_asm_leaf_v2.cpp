#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CUnlockDisplayObject (stub_classes.h)
// 1 functions, 136 bytes

// 0x800799CC (136 bytes)
// CUnlockDisplayObject::SetMultiColorIndex(int)
__attribute__((noreturn))
void CUnlockDisplayObject::SetMultiColorIndex(int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr	30,4\n"
        "lwz	0,116(31)\n"
        "stw	30,24(31)\n"
        "cmpwi	0,0\n"
        "beq	.L_80079A40\n"
        "lwz	3,28(31)\n"
        "lwz	9,0(3)\n"
        "lha	0,280(9)\n"
        "lwz	9,284(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_80079A40\n"
        "lwz	11,28(31)\n"
        "mr	4,30\n"
        "lwz	9,0(11)\n"
        "lwz	0,292(9)\n"
        "lha	3,288(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,-1\n"
        "stw	0,24(31)\n"
        ".L_80079A40:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

