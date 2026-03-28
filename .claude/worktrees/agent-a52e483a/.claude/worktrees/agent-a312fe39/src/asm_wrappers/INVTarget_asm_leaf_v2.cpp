#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for INVTarget (stub_classes.h)
// 2 functions, 192 bytes

// 0x801EE1A4 (92 bytes)
// INVTarget::GetPlayerFunds(void) const
__attribute__((noreturn))
void INVTarget::GetPlayerFunds(void) const {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21496(13)\n"
        "cmpwi	11,0\n"
        "bne	.L_801EE1C4\n"
        "li	3,0\n"
        "b	.L_801EE1F0\n"
        ".L_801EE1C4:\n"
        "lwz	0,132(3)\n"
        "li	4,1\n"
        "cmpwi	0,0\n"
        "bne	.L_801EE1D8\n"
        "li	4,0\n"
        ".L_801EE1D8:\n"
        "lwz	9,0(11)\n"
        "lha	3,160(9)\n"
        "lwz	0,164(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801EE1F0:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801EE200 (100 bytes)
// INVTarget::SetPlayerFunds(int)
__attribute__((noreturn))
void INVTarget::SetPlayerFunds(int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21496(13)\n"
        "cmpwi	11,0\n"
        "bne	.L_801EE220\n"
        "li	3,0\n"
        "b	.L_801EE254\n"
        ".L_801EE220:\n"
        "lwz	0,132(3)\n"
        "li	4,1\n"
        "cmpwi	0,0\n"
        "bne	.L_801EE234\n"
        "li	4,0\n"
        ".L_801EE234:\n"
        "lwz	9,0(11)\n"
        "li	5,0\n"
        "lha	3,208(9)\n"
        "lwz	0,212(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "li	3,1\n"
        ".L_801EE254:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

