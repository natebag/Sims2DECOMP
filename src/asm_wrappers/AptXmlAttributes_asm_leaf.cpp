#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptXmlAttributes (stub_classes.h)
// 1 functions, 164 bytes

// 0x802C4ED8 (164 bytes)
// AptXmlAttributes::objectMemberSet(AptValue *, EAStringC *, AptValue *)
__attribute__((noreturn))
void AptXmlAttributes::objectMemberSet(AptValue *, EAStringC *, AptValue *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,0(4)\n"
        "clrlwi	0,0,25\n"
        "cmpwi	0,34\n"
        "bne	.L_802C4F68\n"
        "lwz	0,0(6)\n"
        "li	10,0\n"
        "mr	9,0\n"
        "clrlwi	0,0,25\n"
        "cmpwi	0,1\n"
        "beq	.L_802C4F14\n"
        "cmpwi	0,42\n"
        "bne	.L_802C4F20\n"
        ".L_802C4F14:\n"
        "andis.	0,9,2048\n"
        "beq	.L_802C4F20\n"
        "li	10,1\n"
        ".L_802C4F20:\n"
        "cmpwi	10,0\n"
        "beq	.L_802C4F68\n"
        "lwz	10,36(4)\n"
        "clrlwi	0,9,25\n"
        "cmpwi	0,1\n"
        "lwz	11,0(5)\n"
        "lwz	9,0(10)\n"
        "addi	4,11,8\n"
        "lha	0,40(9)\n"
        "addi	8,9,40\n"
        "add	3,10,0\n"
        "beq	.L_802C4F54\n"
        "lwz	6,36(6)\n"
        ".L_802C4F54:\n"
        "lwz	5,12(6)\n"
        "lwz	0,4(8)\n"
        "addi	5,5,8\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802C4F68:\n"
        "li	3,1\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

