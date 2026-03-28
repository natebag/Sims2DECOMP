#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptLine (stub_classes.h)
// 2 functions, 196 bytes

// 0x8000DFA8 (80 bytes)
// AptLine::UnlinkWord(AptWord *)
__attribute__((noreturn))
void AptLine::UnlinkWord(AptWord *) {
    __asm__ __volatile__(
        "mr	11,3\n"
        "li	9,0\n"
        "lwz	3,4(11)\n"
        ".L_8000DFB4:\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "cmpw	3,4\n"
        "beq	.L_8000DFD0\n"
        "mr	9,3\n"
        "lwz	3,0(3)\n"
        "b	.L_8000DFB4\n"
        ".L_8000DFD0:\n"
        "cmpwi	3,0\n"
        "beqlr\n"
        "cmpwi	9,0\n"
        "beq	.L_8000DFEC\n"
        "lwz	0,0(3)\n"
        "stw	0,0(9)\n"
        "blr\n"
        ".L_8000DFEC:\n"
        "lwz	0,0(3)\n"
        "stw	0,4(11)\n"
        "blr\n"
    );
}

// 0x8000DFF8 (116 bytes)
// AptLine::Draw(ERC *, EMat4 *, EVec4 *, EVec4 *)
__attribute__((noreturn))
void AptLine::Draw(ERC *, EMat4 *, EVec4 *, EVec4 *) {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "mflr	0\n"
        "stmw	27,12(1)\n"
        "stw	0,36(1)\n"
        "lwz	30,4(3)\n"
        "mr	27,4\n"
        "mr	28,5\n"
        "mr	29,6\n"
        "mr	31,7\n"
        "cmpwi	30,0\n"
        "beq	.L_8000E058\n"
        ".L_8000E024:\n"
        "lwz	9,44(30)\n"
        "mr	4,27\n"
        "mr	5,28\n"
        "mr	6,29\n"
        "lha	3,16(9)\n"
        "mr	7,31\n"
        "lwz	0,20(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "lwz	30,0(30)\n"
        "blrl\n"
        "mr.	30,30\n"
        "bne	.L_8000E024\n"
        ".L_8000E058:\n"
        "lwz	0,36(1)\n"
        "mtlr	0\n"
        "lmw	27,12(1)\n"
        "addi	1,1,32\n"
        "blr\n"
    );
}

