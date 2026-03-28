#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for GameEffectsManager (stub_classes.h)
// 1 functions, 88 bytes

// 0x8003E094 (88 bytes)
// GameEffectsManager::RenderCB(ELevelDrawData &, EOrderTableData *)
__attribute__((noreturn))
void GameEffectsManager::RenderCB(ELevelDrawData &, EOrderTableData *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	11,24(4)\n"
        "mr	31,3\n"
        "cmpwi	11,0\n"
        "beq	.L_8003E0D8\n"
        "lwz	9,324(11)\n"
        "lwz	4,152(31)\n"
        "lwz	0,28(9)\n"
        "lha	3,24(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,168(31)\n"
        ".L_8003E0D8:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

