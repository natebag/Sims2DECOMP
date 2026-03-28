#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ENgcGraphics (stub_classes.h)
// 1 functions, 164 bytes

// 0x8032FCA4 (164 bytes)
// ENgcGraphics::DrawCensorRects(ERC *)
__attribute__((noreturn))
void ENgcGraphics::DrawCensorRects(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-48(1)\n"
        "mflr	0\n"
        "stmw	27,28(1)\n"
        "stw	0,52(1)\n"
        "mr	28,3\n"
        "li	29,0\n"
        "lwz	0,676(28)\n"
        "mr	27,4\n"
        "cmpw	29,0\n"
        "bge	.L_8032FD2C\n"
        "addi	30,1,8\n"
        "addi	31,28,428\n"
        ".L_8032FCD4:\n"
        "lfs	0,-200(31)\n"
        "mr	4,30\n"
        "lfs	12,-196(31)\n"
        "addi	5,1,16\n"
        "stfs	0,8(1)\n"
        "addi	29,29,1\n"
        "lfs	0,-8(31)\n"
        "lfs	13,-4(31)\n"
        "stfs	12,4(30)\n"
        "stfs	0,16(1)\n"
        "stfs	13,20(1)\n"
        "lwz	9,112(27)\n"
        "lfs	1,0(31)\n"
        "lwz	0,836(9)\n"
        "addi	31,31,12\n"
        "lha	3,832(9)\n"
        "mtlr	0\n"
        "add	3,27,3\n"
        "blrl\n"
        "lwz	0,676(28)\n"
        "cmpw	29,0\n"
        "blt	.L_8032FCD4\n"
        ".L_8032FD2C:\n"
        "li	0,0\n"
        "stw	0,676(28)\n"
        "lwz	0,52(1)\n"
        "mtlr	0\n"
        "lmw	27,28(1)\n"
        "addi	1,1,48\n"
        "blr\n"
    );
}

