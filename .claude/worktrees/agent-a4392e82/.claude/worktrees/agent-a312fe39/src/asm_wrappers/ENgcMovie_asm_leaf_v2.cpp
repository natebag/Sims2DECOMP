#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ENgcMovie (stub_classes.h)
// 1 functions, 72 bytes

// 0x803362F8 (72 bytes)
// ENgcMovie::PlayerGetAudioInfo(THPAudioInfo *)
__attribute__((noreturn))
void ENgcMovie::PlayerGetAudioInfo(THPAudioInfo *) {
    __asm__ __volatile__(
        "lis	9,-32691\n"
        "addi	11,9,14656\n"
        "lwz	0,160(11)\n"
        "cmpwi	0,0\n"
        "bne	.L_80336314\n"
        "li	3,0\n"
        "blr\n"
        ".L_80336314:\n"
        "lwz	8,140(11)\n"
        "addi	9,11,140\n"
        "lwz	0,12(9)\n"
        "li	3,1\n"
        "lwz	11,4(9)\n"
        "lwz	10,8(9)\n"
        "stw	0,12(4)\n"
        "stw	8,0(4)\n"
        "stw	11,4(4)\n"
        "stw	10,8(4)\n"
        "blr\n"
    );
}

