#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for INGTarget (stub_classes.h)
// 1 functions, 104 bytes

// 0x801BC9A8 (104 bytes)
// INGTarget::onHelpDialogSelection(int)
__attribute__((noreturn))
void INGTarget::onHelpDialogSelection(int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,308(11)\n"
        "addi	9,9,1\n"
        "cmplwi	9,1\n"
        "stw	9,308(11)\n"
        "bgt	.L_801BC9F8\n"
        "lwz	9,128(11)\n"
        "lis	4,-32705\n"
        "lis	5,-32705\n"
        "addi	4,4,5804\n"
        "lha	3,16(9)\n"
        "addi	5,5,6640\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_801BCA00\n"
        ".L_801BC9F8:\n"
        "li	0,0\n"
        "stw	0,308(11)\n"
        ".L_801BCA00:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

