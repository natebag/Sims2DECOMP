#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ISimInstance (stub_classes.h)
// 1 functions, 72 bytes

// 0x800565E0 (72 bytes)
// ISimInstance::GetSelector(void)
__attribute__((noreturn))
void ISimInstance::GetSelector(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,808(3)\n"
        "cmpwi	11,0\n"
        "bne	.L_80056600\n"
        "li	3,0\n"
        "b	.L_80056618\n"
        ".L_80056600:\n"
        "lwz	9,4(11)\n"
        "lha	3,872(9)\n"
        "lwz	0,876(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80056618:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

