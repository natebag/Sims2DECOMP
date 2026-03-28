#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EILight (stub_classes.h)
// 1 functions, 124 bytes

// 0x80227D64 (124 bytes)
// EILight::GetScaledIntensity(void)
__attribute__((noreturn))
void EILight::GetScaledIntensity(void) {
    __asm__ __volatile__(
        "lwz	0,168(4)\n"
        "cmpwi	0,0\n"
        "beq	.L_80227DCC\n"
        "lis	9,-32704\n"
        "lfs	0,156(4)\n"
        "lfs	13,-6532(9)\n"
        "fmr	12,0\n"
        "fcmpu	cr0,0,13\n"
        "bne	.L_80227DA0\n"
        "lfs	0,160(4)\n"
        "fcmpu	cr0,0,13\n"
        "bne	.L_80227DA0\n"
        "lfs	0,164(4)\n"
        "fcmpu	cr0,0,13\n"
        "beq	.L_80227DCC\n"
        ".L_80227DA0:\n"
        "addi	9,4,156\n"
        "lfs	0,140(4)\n"
        "lfs	13,8(9)\n"
        "lfs	11,4(9)\n"
        "fmuls	12,0,12\n"
        "fmuls	13,0,13\n"
        "stfs	12,0(3)\n"
        "fmuls	0,0,11\n"
        "stfs	13,8(3)\n"
        "stfs	0,4(3)\n"
        "blr\n"
        ".L_80227DCC:\n"
        "lfs	0,140(4)\n"
        "stfs	0,0(3)\n"
        "stfs	0,8(3)\n"
        "stfs	0,4(3)\n"
        "blr\n"
    );
}

