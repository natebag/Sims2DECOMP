#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ERoomWall (stub_classes.h)
// 1 functions, 152 bytes

// 0x800295BC (152 bytes)
// ERoomWall::CalWallsOpaque(int)
__attribute__((noreturn))
void ERoomWall::CalWallsOpaque(int) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	31,20(3)\n"
        "cmpwi	31,0\n"
        "bne	.L_800295EC\n"
        "addi	9,3,44\n"
        "slwi	0,4,2\n"
        "stwx	31,9,0\n"
        "li	3,0\n"
        "b	.L_80029640\n"
        ".L_800295EC:\n"
        "slwi	0,4,2\n"
        "addi	9,3,44\n"
        "li	11,1\n"
        "stwx	11,9,0\n"
        "mr	29,0\n"
        "mr	30,9\n"
        "b	.L_8002960C\n"
        ".L_80029608:\n"
        "lwz	31,8(31)\n"
        ".L_8002960C:\n"
        "cmpwi	31,0\n"
        "beq	.L_8002963C\n"
        "lwz	3,0(31)\n"
        "lwz	9,0(3)\n"
        "lha	0,360(9)\n"
        "lwz	9,364(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "mr.	3,3\n"
        "bne	.L_80029608\n"
        "stwx	3,30,29\n"
        ".L_8002963C:\n"
        "lwzx	3,30,29\n"
        ".L_80029640:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

