#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ENgcMemoryCard (stub_classes.h)
// 2 functions, 268 bytes

// 0x80333BF0 (108 bytes)
// ENgcMemoryCard::IsSpaceAvailable(unsigned int, unsigned int, bool &)
__attribute__((noreturn))
void ENgcMemoryCard::IsSpaceAvailable(unsigned int, unsigned int, bool &) {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "mflr	0\n"
        "stmw	29,20(1)\n"
        "stw	0,36(1)\n"
        "lwz	9,0(3)\n"
        "li	29,0\n"
        "stw	29,8(1)\n"
        "mr	30,5\n"
        "addi	5,1,8\n"
        "mr	31,6\n"
        "lha	0,256(9)\n"
        "lwz	9,260(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,8(1)\n"
        "cmplw	0,30\n"
        "blt	.L_80333C44\n"
        "li	0,1\n"
        "stw	0,0(31)\n"
        "b	.L_80333C48\n"
        ".L_80333C44:\n"
        "stw	29,0(31)\n"
        ".L_80333C48:\n"
        "lwz	0,36(1)\n"
        "mtlr	0\n"
        "lmw	29,20(1)\n"
        "addi	1,1,32\n"
        "blr\n"
    );
}

// 0x80333FA0 (160 bytes)
// ENgcMemoryCard::AnyCardsPresent(int &)
__attribute__((noreturn))
void ENgcMemoryCard::AnyCardsPresent(int &) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,4\n"
        "li	0,-1\n"
        "stw	0,0(30)\n"
        "mr	31,3\n"
        "li	4,1\n"
        "lwz	9,0(31)\n"
        "lha	3,160(9)\n"
        "lwz	0,164(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_80333FEC\n"
        "li	0,1\n"
        "stw	0,0(30)\n"
        ".L_80333FEC:\n"
        "lwz	9,0(31)\n"
        "li	4,0\n"
        "lha	3,160(9)\n"
        "lwz	0,164(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_80334018\n"
        "li	0,0\n"
        "stw	0,0(30)\n"
        ".L_80334018:\n"
        "lwz	0,0(30)\n"
        "li	3,1\n"
        "cmpwi	0,-1\n"
        "bne	.L_8033402C\n"
        "li	3,0\n"
        ".L_8033402C:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

