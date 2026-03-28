#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ENgcRenderer (stub_classes.h)
// 4 functions, 488 bytes

// 0x803442D8 (196 bytes)
// ENgcRenderer::ProjectionMatrix(EDLEntry *)
__attribute__((noreturn))
void ENgcRenderer::ProjectionMatrix(EDLEntry *) {
    __asm__ __volatile__(
        "lwz	9,4(4)\n"
        "lis	10,-32688\n"
        "addi	11,10,-12212\n"
        "li	0,2\n"
        "lfs	0,0(9)\n"
        "addi	8,9,16\n"
        "addi	7,9,32\n"
        "addi	6,9,48\n"
        "stfs	0,-12212(10)\n"
        "li	10,1\n"
        "lfs	0,16(9)\n"
        "stfs	0,4(11)\n"
        "lfs	13,32(9)\n"
        "stfs	13,8(11)\n"
        "lfs	0,48(9)\n"
        "stfs	0,12(11)\n"
        "lfs	13,4(9)\n"
        "stfs	13,16(11)\n"
        "lfs	0,4(8)\n"
        "stfs	0,20(11)\n"
        "lfs	13,4(7)\n"
        "stfs	13,24(11)\n"
        "lfs	0,4(6)\n"
        "stfs	0,28(11)\n"
        "lfs	13,8(9)\n"
        "stfs	13,32(11)\n"
        "lfs	0,8(8)\n"
        "stfs	0,36(11)\n"
        "lfs	13,8(7)\n"
        "stfs	13,40(11)\n"
        "lfs	0,8(6)\n"
        "stfs	0,44(11)\n"
        "lfs	13,12(9)\n"
        "stfs	13,48(11)\n"
        "lfs	0,12(8)\n"
        "stfs	0,52(11)\n"
        "lfs	13,12(7)\n"
        "stfs	13,56(11)\n"
        "lfs	0,12(6)\n"
        "stfs	0,60(11)\n"
        "lwz	9,1240(3)\n"
        "stw	0,2520(9)\n"
        "lwz	11,1240(3)\n"
        "lwz	0,1740(11)\n"
        "oris	0,0,32768\n"
        "ori	0,0,32\n"
        "stw	0,1740(11)\n"
        "stw	10,1296(3)\n"
        "blr\n"
    );
}

// 0x80344598 (88 bytes)
// ENgcRenderer::EnableGeometryModes(EDLEntry *)
__attribute__((noreturn))
void ENgcRenderer::EnableGeometryModes(EDLEntry *) {
    __asm__ __volatile__(
        "lwz	9,1240(3)\n"
        "lwz	10,4(4)\n"
        "lwz	0,1740(9)\n"
        "oris	0,0,32768\n"
        "stw	0,1740(9)\n"
        "lwz	11,1240(3)\n"
        "lwz	0,1768(11)\n"
        "or	0,0,10\n"
        "stw	0,1768(11)\n"
        "lwz	9,1240(3)\n"
        "lwz	0,1768(9)\n"
        "andi.	11,0,4\n"
        "beq	.L_803445D4\n"
        "li	0,1\n"
        "b	.L_803445E0\n"
        ".L_803445D4:\n"
        "andi.	0,0,2\n"
        "beq	.L_803445E0\n"
        "li	0,2\n"
        ".L_803445E0:\n"
        "stw	0,1948(9)\n"
        "li	0,1\n"
        "stw	0,1296(3)\n"
        "blr\n"
    );
}

// 0x80345220 (100 bytes)
// ENgcRenderer::ZTest(EDLEntry *)
__attribute__((noreturn))
void ENgcRenderer::ZTest(EDLEntry *) {
    __asm__ __volatile__(
        "lbz	0,1(4)\n"
        "li	6,0\n"
        "lbz	8,3(4)\n"
        "lbz	10,2(4)\n"
        "cmpwi	0,0\n"
        "stb	0,17988(3)\n"
        "stb	10,17989(3)\n"
        "stb	8,17990(3)\n"
        "beq	.L_80345248\n"
        "li	6,1\n"
        ".L_80345248:\n"
        "lwz	11,1240(3)\n"
        "lis	9,-32702\n"
        "subfic	7,8,0\n"
        "adde	8,7,8\n"
        "addi	9,9,7688\n"
        "lwz	0,1740(11)\n"
        "slwi	10,10,2\n"
        "lwzx	7,9,10\n"
        "oris	0,0,32768\n"
        "stb	8,948(11)\n"
        "ori	0,0,64\n"
        "stb	6,940(11)\n"
        "stw	0,1740(11)\n"
        "stw	7,944(11)\n"
        "blr\n"
    );
}

// 0x80349F6C (104 bytes)
// ENgcRenderer::GetCurrentRenderMode(void)
__attribute__((noreturn))
void ENgcRenderer::GetCurrentRenderMode(void) {
    __asm__ __volatile__(
        "addi	4,4,868\n"
        "mr	9,3\n"
        "li	11,48\n"
        ".L_80349F78:\n"
        "lwz	0,0(4)\n"
        "addic.	11,11,-24\n"
        "stw	0,0(9)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(9)\n"
        "lwz	0,8(4)\n"
        "stw	0,8(9)\n"
        "lwz	0,12(4)\n"
        "stw	0,12(9)\n"
        "lwz	0,16(4)\n"
        "stw	0,16(9)\n"
        "lwz	0,20(4)\n"
        "addi	4,4,24\n"
        "stw	0,20(9)\n"
        "addi	9,9,24\n"
        "bne	.L_80349F78\n"
        "lwz	0,0(4)\n"
        "stw	0,0(9)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(9)\n"
        "lwz	0,8(4)\n"
        "stw	0,8(9)\n"
        "blr\n"
    );
}

