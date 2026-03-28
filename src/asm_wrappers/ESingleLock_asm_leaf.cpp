#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ESingleLock (stub_classes.h)
// 2 functions, 168 bytes

// 0x802E160C (72 bytes)
// ESingleLock::Lock(unsigned int)
__attribute__((noreturn))
void ESingleLock::Lock(unsigned int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	11,0(30)\n"
        "lwz	9,0(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	3,4(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x802E1654 (96 bytes)
// ESingleLock::Unlock(void)
__attribute__((noreturn))
void ESingleLock::Unlock(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	0,4(31)\n"
        "cmpwi	0,0\n"
        "beq	.L_802E1698\n"
        "lwz	11,0(31)\n"
        "lwz	9,0(11)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "xori	3,3,1\n"
        "stw	3,4(31)\n"
        ".L_802E1698:\n"
        "lwz	3,4(31)\n"
        "xori	3,3,1\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

