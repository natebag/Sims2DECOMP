#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for TheSimsMainMenuState (stub_classes.h)
// 1 functions, 148 bytes

// 0x80098C6C (148 bytes)
// TheSimsMainMenuState::LeavingMainMenuCleanup(void)
__attribute__((noreturn))
void TheSimsMainMenuState::LeavingMainMenuCleanup(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lis	9,-32697\n"
        "li	0,1\n"
        "addi	31,9,23428\n"
        "lwz	11,104(31)\n"
        "stw	0,216(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80098CBC\n"
        "lwz	9,128(11)\n"
        "li	4,3\n"
        "lwz	0,12(9)\n"
        "lha	3,8(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,104(31)\n"
        ".L_80098CBC:\n"
        "lwz	11,84(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80098CEC\n"
        "lwz	9,128(11)\n"
        "li	4,3\n"
        "lwz	0,12(9)\n"
        "lha	3,8(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,84(31)\n"
        ".L_80098CEC:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

