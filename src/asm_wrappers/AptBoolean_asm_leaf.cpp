#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptBoolean (stub_classes.h)
// 1 functions, 132 bytes

// 0x802BB830 (132 bytes)
// AptBoolean::ClearPool(void)
__attribute__((noreturn))
void AptBoolean::ClearPool(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	0,-26916(13)\n"
        "cmpwi	0,0\n"
        "beq	.L_802BB8A0\n"
        ".L_802BB84C:\n"
        "lwz	3,-26916(13)\n"
        "lwz	9,8(3)\n"
        "lwz	31,12(3)\n"
        "lha	0,96(9)\n"
        "lwz	9,100(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	11,-26916(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_802BB894\n"
        "lwz	9,8(11)\n"
        "li	4,3\n"
        "lha	3,120(9)\n"
        "lwz	0,124(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802BB894:\n"
        "cmpwi	31,0\n"
        "stw	31,-26916(13)\n"
        "bne	.L_802BB84C\n"
        ".L_802BB8A0:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

