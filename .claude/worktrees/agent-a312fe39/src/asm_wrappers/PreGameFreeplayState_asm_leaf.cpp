#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for PreGameFreeplayState (stub_classes.h)
// 1 functions, 68 bytes

// 0x8009501C (68 bytes)
// PreGameFreeplayState::Shutdown(void)
__attribute__((noreturn))
void PreGameFreeplayState::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,28(3)\n"
        "cmpwi	11,0\n"
        "beq	.L_80095050\n"
        "lwz	9,128(11)\n"
        "li	4,3\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80095050:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

