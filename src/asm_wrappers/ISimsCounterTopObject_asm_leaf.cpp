#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ISimsCounterTopObject (stub_classes.h)
// 1 functions, 164 bytes

// 0x800548E0 (164 bytes)
// ISimsCounterTopObject::IsSinkId(cXObject *)
__attribute__((noreturn))
void ISimsCounterTopObject::IsSinkId(cXObject *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "li	30,0\n"
        "mr.	31,3\n"
        "beq	.L_8005496C\n"
        "lwz	9,4(31)\n"
        "lha	3,784(9)\n"
        "lwz	0,788(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_8005496C\n"
        "lwz	9,4(31)\n"
        "lwz	0,788(9)\n"
        "lha	3,784(9)\n"
        "mtlr	0\n"
        "add	3,31,3\n"
        "blrl\n"
        "lwz	0,192(3)\n"
        "cmpwi	0,0\n"
        "beq	.L_8005496C\n"
        "lwz	9,4(31)\n"
        "lwz	0,788(9)\n"
        "lha	3,784(9)\n"
        "mtlr	0\n"
        "add	3,31,3\n"
        "blrl\n"
        "lwz	9,192(3)\n"
        "lbz	0,7(9)\n"
        "cmpwi	0,0\n"
        "beq	.L_8005496C\n"
        "li	30,1\n"
        ".L_8005496C:\n"
        "mr	3,30\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

