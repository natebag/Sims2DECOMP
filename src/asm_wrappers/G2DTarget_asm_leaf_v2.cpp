#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for G2DTarget (stub_classes.h)
// 2 functions, 136 bytes

// 0x801B6B24 (68 bytes)
// G2DTarget::ExecuteSelectionCallback(int)
__attribute__((noreturn))
void G2DTarget::ExecuteSelectionCallback(int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,272(11)\n"
        "cmpwi	9,0\n"
        "beq	.L_801B6B58\n"
        "li	0,0\n"
        "mr	3,9\n"
        "stw	0,272(11)\n"
        "lwz	0,12(9)\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801B6B58:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801B6B68 (68 bytes)
// G2DTarget::ExecuteZeroInputCallback(void)
__attribute__((noreturn))
void G2DTarget::ExecuteZeroInputCallback(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,276(11)\n"
        "cmpwi	9,0\n"
        "beq	.L_801B6B9C\n"
        "li	0,0\n"
        "mr	3,9\n"
        "stw	0,276(11)\n"
        "lwz	0,12(9)\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801B6B9C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

