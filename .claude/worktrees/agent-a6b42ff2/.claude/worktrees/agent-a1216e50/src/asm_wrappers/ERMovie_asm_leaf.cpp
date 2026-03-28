#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ERMovie (stub_classes.h)
// 1 functions, 92 bytes

// 0x8031B72C (92 bytes)
// ERMovie::IsFinished(void)
__attribute__((noreturn))
void ERMovie::IsFinished(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	11,36(3)\n"
        "li	31,0\n"
        "cmpwi	11,0\n"
        "beq	.L_8031B76C\n"
        "lwz	9,8(11)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_8031B770\n"
        ".L_8031B76C:\n"
        "li	31,1\n"
        ".L_8031B770:\n"
        "mr	3,31\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

