#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptError (stub_classes.h)
// 1 functions, 92 bytes

// 0x802A83CC (92 bytes)
// AptError::CleanNativeFunctions(void)
__attribute__((noreturn))
void AptError::CleanNativeFunctions(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-27112(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_802A8418\n"
        "lwz	9,8(11)\n"
        "lis	4,-32703\n"
        "lis	5,-32703\n"
        "addi	4,4,-20700\n"
        "lwz	0,20(9)\n"
        "addi	5,5,-21544\n"
        "lha	3,16(9)\n"
        "li	6,1325\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,-27112(13)\n"
        ".L_802A8418:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

