#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for HelpDialog (stub_classes.h)
// 1 functions, 72 bytes

// 0x80175F68 (72 bytes)
// HelpDialog::SelectionCallback(int)
__attribute__((noreturn))
void HelpDialog::SelectionCallback(int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,140(3)\n"
        "li	0,0\n"
        "stw	0,136(3)\n"
        "cmpwi	11,0\n"
        "beq	.L_80175FA0\n"
        "lwz	9,0(11)\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80175FA0:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

