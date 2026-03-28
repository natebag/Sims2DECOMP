#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for LoadingScreenStateMachine (stub_classes.h)
// 1 functions, 92 bytes

// 0x80090B5C (92 bytes)
// LoadingScreenStateMachine::DeleteLoadingScreen(void)
__attribute__((noreturn))
void LoadingScreenStateMachine::DeleteLoadingScreen(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	11,152(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80090BA4\n"
        "lwz	9,912(11)\n"
        "li	4,3\n"
        "lwz	0,12(9)\n"
        "lha	3,8(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,160(31)\n"
        "stw	0,152(31)\n"
        ".L_80090BA4:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

