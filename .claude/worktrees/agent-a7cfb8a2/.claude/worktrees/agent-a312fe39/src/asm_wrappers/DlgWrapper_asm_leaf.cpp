#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for DlgWrapper (stub_classes.h)
// 1 functions, 88 bytes

// 0x8007E8FC (88 bytes)
// DlgWrapper::SetBodyPos(EVec2 &)
__attribute__((noreturn))
void DlgWrapper::SetBodyPos(EVec2 &) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	0,20(1)\n"
        "mr	9,4\n"
        "addi	11,1,8\n"
        "lfs	13,0(9)\n"
        "mr	4,11\n"
        "lfs	0,4(9)\n"
        "stfs	13,8(1)\n"
        "stfs	0,4(11)\n"
        "lwz	9,172(3)\n"
        "lwz	10,100(9)\n"
        "lwz	11,28(10)\n"
        "lha	3,56(11)\n"
        "lwz	0,60(11)\n"
        "add	3,10,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

