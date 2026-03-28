#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cSoundModeManager (stub_classes.h)
// 1 functions, 88 bytes

// 0x800B0400 (88 bytes)
// cSoundModeManager::Unpause(void)
__attribute__((noreturn))
void cSoundModeManager::Unpause(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-26564(13)\n"
        "lwz	9,0(11)\n"
        "lwz	0,92(9)\n"
        "lha	3,88(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	11,-26564(13)\n"
        "li	4,1\n"
        "lwz	9,0(11)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

