#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptValueVector (stub_classes.h)
// 1 functions, 128 bytes

// 0x802BC0F0 (128 bytes)
// AptValueVector::ReleaseValues(void)
__attribute__((noreturn))
void AptValueVector::ReleaseValues(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "b	.L_802BC150\n"
        ".L_802BC108:\n"
        "lwz	9,4(31)\n"
        "lwz	11,8(31)\n"
        "addi	9,9,-1\n"
        "stw	9,4(31)\n"
        "slwi	9,9,2\n"
        "lwzx	11,9,11\n"
        "lwz	0,0(11)\n"
        "rlwinm.	9,0,18,20,31\n"
        "beq	.L_802BC138\n"
        "rlwinm	0,0,0,3,1\n"
        "stw	0,0(11)\n"
        "b	.L_802BC150\n"
        ".L_802BC138:\n"
        "lwz	9,8(11)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802BC150:\n"
        "lwz	0,4(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_802BC108\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

