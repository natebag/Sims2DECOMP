#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for TextureUtils (stub_classes.h)
// 2 functions, 168 bytes

// 0x8030C5B4 (100 bytes)
// TextureUtils::PrepareTextureForUpdateBegin(ETexture *)
__attribute__((noreturn))
void TextureUtils::PrepareTextureForUpdateBegin(ETexture *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr.	11,3\n"
        "bne	.L_8030C5D4\n"
        "li	3,0\n"
        "b	.L_8030C604\n"
        ".L_8030C5D4:\n"
        "lwz	0,8(11)\n"
        "li	31,0\n"
        "andi.	9,0,128\n"
        "beq	.L_8030C600\n"
        "lwz	9,36(11)\n"
        "li	31,1\n"
        "lha	3,96(9)\n"
        "lwz	0,100(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8030C600:\n"
        "mr	3,31\n"
        ".L_8030C604:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8030C618 (68 bytes)
// TextureUtils::PostUpdateEnd(ETexture *, bool)
__attribute__((noreturn))
void TextureUtils::PostUpdateEnd(ETexture *, bool) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr.	11,3\n"
        "beq	.L_8030C64C\n"
        "cmpwi	4,0\n"
        "beq	.L_8030C64C\n"
        "lwz	9,36(11)\n"
        "lha	3,104(9)\n"
        "lwz	0,108(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8030C64C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

