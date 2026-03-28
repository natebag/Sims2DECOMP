#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cXMTObject (stub_classes.h)
// 1 functions, 68 bytes

// 0x800C7CD0 (68 bytes)
// cXMTObject::CAST_IMPL(void)
__attribute__((noreturn))
void cXMTObject::CAST_IMPL(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr.	11,3\n"
        "bne	.L_800C7CEC\n"
        "li	3,0\n"
        "b	.L_800C7D04\n"
        ".L_800C7CEC:\n"
        "lwz	9,4(11)\n"
        "lha	3,88(9)\n"
        "lwz	0,92(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800C7D04:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

