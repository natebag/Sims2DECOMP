#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EFixedString (stub_classes.h)
// 1 functions, 132 bytes

// 0x802C82F4 (132 bytes)
// EFixedString::MakeLegalFilename(void)
__attribute__((noreturn))
void EFixedString::MakeLegalFilename(void) {
    __asm__ __volatile__(
        "lwz	9,0(3)\n"
        "li	11,95\n"
        ".L_802C82FC:\n"
        "lbz	0,0(9)\n"
        "extsb	0,0\n"
        "cmpwi	0,58\n"
        "beq	.L_802C836C\n"
        "bgt	.L_802C8340\n"
        "cmpwi	0,35\n"
        "bgt	.L_802C832C\n"
        "cmpwi	0,34\n"
        "bge	.L_802C836C\n"
        "cmpwi	0,0\n"
        "beqlr\n"
        "b	.L_802C8370\n"
        ".L_802C832C:\n"
        "cmpwi	0,42\n"
        "beq	.L_802C836C\n"
        "cmpwi	0,47\n"
        "beq	.L_802C836C\n"
        "b	.L_802C8370\n"
        ".L_802C8340:\n"
        "cmpwi	0,63\n"
        "bgt	.L_802C835C\n"
        "cmpwi	0,62\n"
        "bge	.L_802C836C\n"
        "cmpwi	0,60\n"
        "beq	.L_802C836C\n"
        "b	.L_802C8370\n"
        ".L_802C835C:\n"
        "cmpwi	0,92\n"
        "beq	.L_802C836C\n"
        "cmpwi	0,124\n"
        "bne	.L_802C8370\n"
        ".L_802C836C:\n"
        "stb	11,0(9)\n"
        ".L_802C8370:\n"
        "addi	9,9,1\n"
        "b	.L_802C82FC\n"
    );
}

