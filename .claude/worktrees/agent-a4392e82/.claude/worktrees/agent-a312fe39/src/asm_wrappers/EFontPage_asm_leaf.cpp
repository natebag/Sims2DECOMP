#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EFontPage (stub_classes.h)
// 1 functions, 164 bytes

// 0x80363864 (164 bytes)
// EFontPage::Write(EStream &)
__attribute__((noreturn))
void EFontPage::Write(EStream &) {
    __asm__ __volatile__(
        "stwu	1,-40(1)\n"
        "mflr	0\n"
        "stmw	29,28(1)\n"
        "stw	0,44(1)\n"
        "mr	30,4\n"
        "mr	29,3\n"
        "lwz	9,24(30)\n"
        "addi	4,1,8\n"
        "li	5,4\n"
        "lwz	0,4(29)\n"
        "lha	3,56(9)\n"
        "lwz	9,60(9)\n"
        "add	3,30,3\n"
        "stw	0,8(1)\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	9,24(30)\n"
        "addi	4,1,12\n"
        "li	5,4\n"
        "lwz	0,12(29)\n"
        "lha	3,56(9)\n"
        "lwz	9,60(9)\n"
        "add	3,30,3\n"
        "stw	0,12(1)\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	9,24(30)\n"
        "addi	4,1,16\n"
        "li	5,4\n"
        "lwz	0,16(29)\n"
        "lha	3,56(9)\n"
        "lwz	9,60(9)\n"
        "add	3,30,3\n"
        "stw	0,16(1)\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,44(1)\n"
        "mtlr	0\n"
        "lmw	29,28(1)\n"
        "addi	1,1,40\n"
        "blr\n"
    );
}

