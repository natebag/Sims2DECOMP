#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for E2ETarget (stub_classes.h)
// 1 functions, 76 bytes

// 0x801ACA0C (76 bytes)
// E2ETarget::OnShutdown(void)
__attribute__((noreturn))
void E2ETarget::OnShutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lis	9,-32697\n"
        "lis	4,-32705\n"
        "lwz	11,24312(9)\n"
        "lis	5,-32705\n"
        "addi	4,4,-5352\n"
        "addi	5,5,-5340\n"
        "lwz	9,128(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

