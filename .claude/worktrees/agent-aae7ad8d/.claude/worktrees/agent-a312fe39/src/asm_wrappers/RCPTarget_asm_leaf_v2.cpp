#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for RCPTarget (stub_classes.h)
// 1 functions, 128 bytes

// 0x801DE4B4 (128 bytes)
// RCPTarget::Update(void)
__attribute__((noreturn))
void RCPTarget::Update(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,324(3)\n"
        "cmpwi	0,0\n"
        "bne	.L_801DE524\n"
        "lis	9,-32705\n"
        "lfs	13,320(3)\n"
        "lfs	12,21164(9)\n"
        "fcmpu	cr0,13,12\n"
        "ble	.L_801DE524\n"
        "lfs	0,-26800(13)\n"
        "fsubs	0,13,0\n"
        "fcmpu	cr0,0,12\n"
        "stfs	0,320(3)\n"
        "cror	so,eq,lt\n"
        "bns	.L_801DE524\n"
        "lwz	11,288(3)\n"
        "li	0,1\n"
        "stw	0,324(3)\n"
        "cmpwi	11,0\n"
        "beq	.L_801DE524\n"
        "lwz	9,0(11)\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801DE524:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

