#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ESimShadow (stub_classes.h)
// 1 functions, 112 bytes

// 0x80032E88 (112 bytes)
// ESimShadow::GetShadowCenter(EVec3 &) const
__attribute__((noreturn))
void ESimShadow::GetShadowCenter(EVec3 &) const {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	11,800(3)\n"
        "mr	30,4\n"
        "lwz	9,4(11)\n"
        "lwz	0,396(9)\n"
        "lha	3,392(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "li	4,2\n"
        "mr	5,30\n"
        "lha	0,224(9)\n"
        "lwz	9,228(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lis	9,-32707\n"
        "lfs	0,4496(9)\n"
        "stfs	0,8(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

