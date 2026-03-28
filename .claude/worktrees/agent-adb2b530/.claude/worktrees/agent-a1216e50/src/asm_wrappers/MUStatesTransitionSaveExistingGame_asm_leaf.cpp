#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for MUStatesTransitionSaveExistingGame (stub_classes.h)
// 1 functions, 120 bytes

// 0x80092EE4 (120 bytes)
// MUStatesTransitionSaveExistingGame::Draw(ERC *)
__attribute__((noreturn))
void MUStatesTransitionSaveExistingGame::Draw(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	9,28(31)\n"
        "addi	9,9,-8\n"
        "cmplwi	9,1\n"
        "bgt	.L_80092F48\n"
        "lwz	11,8(31)\n"
        "li	0,0\n"
        "lwz	9,152(11)\n"
        "stw	0,200(9)\n"
        "lwz	11,8(31)\n"
        "lwz	10,152(11)\n"
        "lwz	9,128(10)\n"
        "lwz	0,52(9)\n"
        "lha	3,48(9)\n"
        "mtlr	0\n"
        "add	3,10,3\n"
        "blrl\n"
        "lwz	11,8(31)\n"
        "li	0,1\n"
        "lwz	9,152(11)\n"
        "stw	0,200(9)\n"
        ".L_80092F48:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

