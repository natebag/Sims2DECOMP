#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EInstance (stub_classes.h)
// 4 functions, 348 bytes

// 0x8022922C (68 bytes)
// EInstance::SetInstAlpha(float)
__attribute__((noreturn))
void EInstance::SetInstAlpha(float) {
    __asm__ __volatile__(
        "lis	9,-32704\n"
        "lfs	0,-6112(9)\n"
        "fcmpu	cr0,1,0\n"
        "cror	so,eq,lt\n"
        "bns	.L_80229244\n"
        "fmr	1,0\n"
        ".L_80229244:\n"
        "lis	9,-32704\n"
        "lfs	0,-6108(9)\n"
        "fcmpu	cr0,1,0\n"
        "cror	so,eq,gt\n"
        "bns	.L_8022925C\n"
        "fmr	1,0\n"
        ".L_8022925C:\n"
        "lwz	0,-28496(13)\n"
        "addi	9,3,96\n"
        "slwi	0,0,2\n"
        "stfsx	1,9,0\n"
        "blr\n"
    );
}

// 0x802294AC (124 bytes)
// EInstance::ResetLocation(void)
__attribute__((noreturn))
void EInstance::ResetLocation(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stw	31,20(1)\n"
        "stw	0,28(1)\n"
        "mr	31,3\n"
        "lwz	0,28(31)\n"
        "cmpwi	0,0\n"
        "beq	.L_802294E8\n"
        "lwz	3,40(31)\n"
        "li	4,1\n"
        "addi	5,1,8\n"
        "addi	6,1,10\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_802294F0\n"
        ".L_802294E8:\n"
        "sth	0,8(1)\n"
        "sth	0,10(1)\n"
        ".L_802294F0:\n"
        "lwz	0,32(31)\n"
        "cmpwi	0,0\n"
        "beq	.L_80229514\n"
        "lwz	3,36(31)\n"
        "li	4,1\n"
        "addi	5,1,8\n"
        "addi	6,1,10\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80229514:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lwz	31,20(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x80229528 (76 bytes)
// EInstance::GetLocationId(short &, short &)
__attribute__((noreturn))
void EInstance::GetLocationId(short &, short &) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,28(3)\n"
        "mr	6,5\n"
        "cmpwi	0,0\n"
        "beq	.L_8022955C\n"
        "mr	5,4\n"
        "lwz	3,40(3)\n"
        "li	4,0\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_80229564\n"
        ".L_8022955C:\n"
        "sth	0,0(6)\n"
        "sth	0,0(4)\n"
        ".L_80229564:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x80229574 (80 bytes)
// EInstance::GetOtherSide(short &, short &)
__attribute__((noreturn))
void EInstance::GetOtherSide(short &, short &) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,32(3)\n"
        "mr	6,5\n"
        "cmpwi	0,0\n"
        "beq	.L_802295A8\n"
        "mr	5,4\n"
        "lwz	3,36(3)\n"
        "li	4,0\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_802295B4\n"
        ".L_802295A8:\n"
        "li	0,-1\n"
        "sth	0,0(6)\n"
        "sth	0,0(4)\n"
        ".L_802295B4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

