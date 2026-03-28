#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for UIObjectBase (stub_classes.h)
// 2 functions, 140 bytes

// 0x80177CC8 (68 bytes)
// UIObjectBase::UIRouter_SetVariable(char *, char *)
__attribute__((noreturn))
void UIObjectBase::UIRouter_SetVariable(char *, char *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lis	9,-32697\n"
        "mr	5,4\n"
        "lwz	11,24312(9)\n"
        "mr	4,3\n"
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

// 0x80177D0C (72 bytes)
// UIObjectBase::UIRouter_FlowGoto(char *)
__attribute__((noreturn))
void UIObjectBase::UIRouter_FlowGoto(char *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lis	9,-32697\n"
        "mr	5,3\n"
        "lwz	11,24312(9)\n"
        "lis	4,-32706\n"
        "addi	4,4,9360\n"
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

