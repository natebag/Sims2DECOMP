#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cSoundCache (stub_classes.h)
// 1 functions, 108 bytes

// 0x80119530 (108 bytes)
// cSoundCache::Shutdown(void)
__attribute__((noreturn))
void cSoundCache::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	28,8(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "li	28,0\n"
        "li	31,0\n"
        "li	29,64\n"
        ".L_80119550:\n"
        "lwzx	11,31,30\n"
        "li	4,3\n"
        "cmpwi	11,0\n"
        "beq	.L_8011957C\n"
        "lwz	9,148(11)\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stwx	28,31,30\n"
        ".L_8011957C:\n"
        "addi	31,31,4\n"
        "addic.	29,29,-1\n"
        "bne	.L_80119550\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	28,8(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

