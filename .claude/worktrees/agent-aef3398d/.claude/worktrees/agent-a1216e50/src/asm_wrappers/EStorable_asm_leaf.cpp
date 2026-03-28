#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EStorable (stub_classes.h)
// 1 functions, 92 bytes

// 0x802D1498 (92 bytes)
// EStorable::IsExactType(ETypeInfo *) const
__attribute__((noreturn))
void EStorable::IsExactType(ETypeInfo *) const {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,4\n"
        "mr.	11,3\n"
        "bne	.L_802D14BC\n"
        "li	3,0\n"
        "b	.L_802D14E0\n"
        ".L_802D14BC:\n"
        "lwz	9,0(11)\n"
        "lwz	0,20(9)\n"
        "lha	3,16(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "xor	3,3,31\n"
        "subfic	0,3,0\n"
        "adde	3,0,3\n"
        ".L_802D14E0:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

