#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for UIAUDIO (stub_classes.h)
// 1 functions, 76 bytes

// 0x80177A18 (76 bytes)
// UIAUDIO::Shutdown(void)
__attribute__((noreturn))
void UIAUDIO::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-31536(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_80177A54\n"
        "lwz	9,116(11)\n"
        "li	4,3\n"
        "lwz	0,12(9)\n"
        "lha	3,8(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,-31536(13)\n"
        ".L_80177A54:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

