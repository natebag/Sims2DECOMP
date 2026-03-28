#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for StartScreenVars (stub_classes.h)
// 1 functions, 68 bytes

// 0x80095570 (68 bytes)
// StartScreenVars::Shutdown(void)
__attribute__((noreturn))
void StartScreenVars::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,32(3)\n"
        "cmpwi	11,0\n"
        "beq	.L_800955A4\n"
        "lwz	9,156(11)\n"
        "li	4,3\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800955A4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

