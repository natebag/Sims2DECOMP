#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptValue (stub_classes.h)
// 1 functions, 124 bytes

// 0x802B41CC (124 bytes)
// AptValue::ForceDelete(void)
__attribute__((noreturn))
void AptValue::ForceDelete(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	9,8(31)\n"
        "lwz	0,92(9)\n"
        "lha	3,88(9)\n"
        "mtlr	0\n"
        "add	3,31,3\n"
        "blrl\n"
        "lwz	9,8(31)\n"
        "lha	3,96(9)\n"
        "lwz	0,100(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	31,0\n"
        "beq	.L_802B4234\n"
        "lwz	9,8(31)\n"
        "li	4,3\n"
        "lha	3,120(9)\n"
        "lwz	0,124(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802B4234:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

