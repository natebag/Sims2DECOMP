#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptFloat (stub_classes.h)
// 1 functions, 132 bytes

// 0x802BBAE0 (132 bytes)
// AptFloat::ClearPool(void)
__attribute__((noreturn))
void AptFloat::ClearPool(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	0,-26912(13)\n"
        "cmpwi	0,0\n"
        "beq	.L_802BBB50\n"
        ".L_802BBAFC:\n"
        "lwz	3,-26912(13)\n"
        "lwz	9,8(3)\n"
        "lwz	31,12(3)\n"
        "lha	0,96(9)\n"
        "lwz	9,100(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	11,-26912(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_802BBB44\n"
        "lwz	9,8(11)\n"
        "li	4,3\n"
        "lha	3,120(9)\n"
        "lwz	0,124(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802BBB44:\n"
        "cmpwi	31,0\n"
        "stw	31,-26912(13)\n"
        "bne	.L_802BBAFC\n"
        ".L_802BBB50:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

