#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CasSimRenderer (stub_classes.h)
// 1 functions, 172 bytes

// 0x8016F860 (172 bytes)
// CasSimRenderer::SetFaceImage(ETexture *)
__attribute__((noreturn))
void CasSimRenderer::SetFaceImage(ETexture *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,4\n"
        "mr	31,3\n"
        "lwz	4,528(31)\n"
        "cmpw	30,4\n"
        "beq	.L_8016F8F8\n"
        "cmpwi	4,0\n"
        "beq	.L_8016F8F4\n"
        "lwz	3,-26392(13)\n"
        "lwz	9,0(3)\n"
        "lha	0,200(9)\n"
        "lwz	9,204(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_8016F8CC\n"
        "lwz	3,-26392(13)\n"
        "lwz	9,0(3)\n"
        "lha	0,64(9)\n"
        "lwz	9,68(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        ".L_8016F8CC:\n"
        "lwz	11,-26392(13)\n"
        "lwz	4,528(31)\n"
        "lwz	9,0(11)\n"
        "lwz	0,196(9)\n"
        "lha	3,192(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,528(31)\n"
        ".L_8016F8F4:\n"
        "stw	30,528(31)\n"
        ".L_8016F8F8:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

