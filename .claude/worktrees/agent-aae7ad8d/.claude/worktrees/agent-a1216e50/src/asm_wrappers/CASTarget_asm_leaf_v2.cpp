#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CASTarget (stub_classes.h)
// 1 functions, 84 bytes

// 0x80196420 (84 bytes)
// CASTarget::ResetSimRotations(void)
__attribute__((noreturn))
void CASTarget::ResetSimRotations(void) {
    __asm__ __volatile__(
        "li	0,4\n"
        "lis	9,-32705\n"
        "mtctr	0\n"
        "lfs	0,-15264(9)\n"
        "li	11,0\n"
        "addi	10,3,2632\n"
        ".L_80196438:\n"
        "mr	0,11\n"
        "cmpwi	11,0\n"
        "bge	.L_80196448\n"
        "addi	0,11,3\n"
        ".L_80196448:\n"
        "clrrwi	0,0,2\n"
        "lwz	9,4936(3)\n"
        "subf	0,0,11\n"
        "srw	9,9,0\n"
        "andi.	0,9,1\n"
        "beq	.L_80196464\n"
        "stfs	0,524(10)\n"
        ".L_80196464:\n"
        "addi	10,10,576\n"
        "addi	11,11,1\n"
        "bdnz	.L_80196438\n"
        "blr\n"
    );
}

