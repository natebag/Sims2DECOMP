#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptPrototype (stub_classes.h)
// 1 functions, 152 bytes

// 0x802B6220 (152 bytes)
// AptPrototype::SetSuperConstructor(AptValue *)
__attribute__((noreturn))
void AptPrototype::SetSuperConstructor(AptValue *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	11,4\n"
        "lwz	31,32(3)\n"
        "cmpwi	11,0\n"
        "stw	11,32(3)\n"
        "beq	.L_802B6270\n"
        "lwz	9,8(11)\n"
        "lis	4,-32703\n"
        "lis	5,-32703\n"
        "addi	4,4,19328\n"
        "lha	3,8(9)\n"
        "addi	5,5,19380\n"
        "lwz	0,12(9)\n"
        "li	6,218\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802B6270:\n"
        "cmpwi	31,0\n"
        "beq	.L_802B62A4\n"
        "lwz	9,8(31)\n"
        "lis	4,-32703\n"
        "lis	5,-32703\n"
        "addi	4,4,19328\n"
        "lha	3,16(9)\n"
        "addi	5,5,19380\n"
        "lwz	0,20(9)\n"
        "li	6,219\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802B62A4:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

