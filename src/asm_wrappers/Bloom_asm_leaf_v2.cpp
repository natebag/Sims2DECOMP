#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for Bloom (stub_classes.h)
// 1 functions, 116 bytes

// 0x803576E0 (116 bytes)
// Bloom::SetTargetSettings(BloomSettings &)
__attribute__((noreturn))
void Bloom::SetTargetSettings(BloomSettings &) {
    __asm__ __volatile__(
        "addi	3,3,20\n"
        "li	9,24\n"
        ".L_803576E8:\n"
        "lwz	0,0(4)\n"
        "addic.	9,9,-24\n"
        "stw	0,0(3)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(3)\n"
        "lwz	0,8(4)\n"
        "stw	0,8(3)\n"
        "lwz	0,12(4)\n"
        "stw	0,12(3)\n"
        "lwz	0,16(4)\n"
        "stw	0,16(3)\n"
        "lwz	0,20(4)\n"
        "addi	4,4,24\n"
        "stw	0,20(3)\n"
        "addi	3,3,24\n"
        "bne	.L_803576E8\n"
        "lwz	0,0(4)\n"
        "stw	0,0(3)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(3)\n"
        "lwz	0,8(4)\n"
        "stw	0,8(3)\n"
        "lwz	0,12(4)\n"
        "stw	0,12(3)\n"
        "lwz	0,16(4)\n"
        "stw	0,16(3)\n"
        "blr\n"
    );
}

