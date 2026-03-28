#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptStringObject (stub_classes.h)
// 1 functions, 92 bytes

// 0x80281E94 (92 bytes)
// AptStringObject::setString(AptString *)
__attribute__((noreturn))
void AptStringObject::setString(AptString *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	30,4\n"
        "mr	29,3\n"
        "lwz	9,8(30)\n"
        "lis	4,-32704\n"
        "lis	5,-32704\n"
        "addi	4,4,5528\n"
        "lha	3,8(9)\n"
        "addi	5,5,5412\n"
        "lwz	0,12(9)\n"
        "li	6,335\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	30,36(29)\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

