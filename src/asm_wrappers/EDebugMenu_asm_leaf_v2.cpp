#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EDebugMenu (stub_classes.h)
// 1 functions, 128 bytes

// 0x80305E10 (128 bytes)
// EDebugMenu::Remove(EDebugMenuItem &)
__attribute__((noreturn))
void EDebugMenu::Remove(EDebugMenuItem &) {
    __asm__ __volatile__(
        "lwz	0,12(3)\n"
        "addi	11,3,12\n"
        "cmpw	0,4\n"
        "bne	.L_80305E2C\n"
        "lwz	0,4(4)\n"
        "stw	0,12(3)\n"
        "b	.L_80305E38\n"
        ".L_80305E2C:\n"
        "lwz	9,0(4)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(9)\n"
        ".L_80305E38:\n"
        "lwz	0,4(11)\n"
        "cmpw	0,4\n"
        "bne	.L_80305E50\n"
        "lwz	0,0(4)\n"
        "stw	0,4(11)\n"
        "b	.L_80305E5C\n"
        ".L_80305E50:\n"
        "lwz	0,0(4)\n"
        "lwz	9,4(4)\n"
        "stw	0,0(9)\n"
        ".L_80305E5C:\n"
        "lwz	9,24(3)\n"
        "li	0,1\n"
        "stw	0,8(3)\n"
        "addi	9,9,-1\n"
        "stw	9,24(3)\n"
        "cmpwi	9,0\n"
        "beqlr\n"
        "lwz	11,20(3)\n"
        "cmpw	11,9\n"
        "bltlr\n"
        "addi	0,11,-1\n"
        "stw	0,20(3)\n"
        "blr\n"
    );
}

