#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for Player (stub_classes.h)
// 1 functions, 164 bytes

// 0x800595B8 (164 bytes)
// Player::GetPrimaryNeighbor(void)
__attribute__((noreturn))
void Player::GetPrimaryNeighbor(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	31,-21476(13)\n"
        "mr	29,3\n"
        "lis	9,-32697\n"
        "li	30,0\n"
        "lwz	11,0(31)\n"
        "lwz	4,23644(9)\n"
        "lha	3,288(11)\n"
        "lwz	0,292(11)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr.	11,3\n"
        "beq	.L_80059640\n"
        "lwz	9,0(11)\n"
        "lwz	4,0(29)\n"
        "lha	3,56(9)\n"
        "lwz	0,60(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr.	3,3\n"
        "beq	.L_80059640\n"
        "lwz	9,0(31)\n"
        "lwz	4,0(3)\n"
        "lha	3,192(9)\n"
        "lwz	0,196(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	30,3\n"
        ".L_80059640:\n"
        "stw	30,4(29)\n"
        "mr	3,30\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

