#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ESemaphore (stub_classes.h)
// 2 functions, 140 bytes

// 0x802D7A08 (72 bytes)
// ESemaphore::operator++(void)
__attribute__((noreturn))
void ESemaphore::operator++(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "li	4,-1\n"
        "lwz	9,0(30)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	3,30\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x802D7A98 (68 bytes)
// ESemaphore::operator--(void)
__attribute__((noreturn))
void ESemaphore::operator--(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	9,0(30)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	3,30\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

