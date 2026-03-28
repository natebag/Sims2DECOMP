#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for O2TTarget (stub_classes.h)
// 1 functions, 108 bytes

// 0x801CEAC0 (108 bytes)
// O2TTarget::Shutdown(char *, char *)
__attribute__((noreturn))
void O2TTarget::Shutdown(char *, char *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,144(3)\n"
        "cmpwi	0,0\n"
        "bne	.L_801CEB1C\n"
        "lwz	0,584(3)\n"
        "cmpwi	0,0\n"
        "bne	.L_801CEB1C\n"
        "li	0,1\n"
        "lis	9,-32697\n"
        "stw	0,596(3)\n"
        "lis	4,-32705\n"
        "lis	5,-32705\n"
        "addi	4,4,-5352\n"
        "lwz	11,24312(9)\n"
        "addi	5,5,-5340\n"
        "lwz	9,128(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801CEB1C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

