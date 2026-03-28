#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptObject (stub_classes.h)
// 1 functions, 152 bytes

// 0x802B64C4 (152 bytes)
// AptObject::SetPrototype(AptValue *)
__attribute__((noreturn))
void AptObject::SetPrototype(AptValue *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "addi	30,3,12\n"
        "mr.	31,4\n"
        "beq	.L_802B650C\n"
        "lwz	9,8(31)\n"
        "lis	4,-32703\n"
        "lis	5,-32703\n"
        "addi	4,4,18948\n"
        "lha	3,8(9)\n"
        "addi	5,5,18820\n"
        "lwz	0,12(9)\n"
        "li	6,102\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802B650C:\n"
        "lwz	11,12(30)\n"
        "cmpwi	11,0\n"
        "beq	.L_802B6544\n"
        "lwz	9,8(11)\n"
        "lis	4,-32703\n"
        "lis	5,-32703\n"
        "addi	4,4,18948\n"
        "lha	3,16(9)\n"
        "addi	5,5,18820\n"
        "lwz	0,20(9)\n"
        "li	6,103\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802B6544:\n"
        "stw	31,12(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

