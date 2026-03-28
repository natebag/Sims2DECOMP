#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CTGFileImpl (stub_classes.h)
// 3 functions, 336 bytes

// 0x8007CFD4 (68 bytes)
// CTGFileImpl::ReadBytes(unsigned char *, int)
__attribute__((noreturn))
void CTGFileImpl::ReadBytes(unsigned char *, int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,0(3)\n"
        "lha	0,16(9)\n"
        "lwz	9,20(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "li	3,1\n"
        "bne	.L_8007D008\n"
        "li	3,0\n"
        ".L_8007D008:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x8007D018 (76 bytes)
// CTGFileImpl::WriteBytes(unsigned char *, int)
__attribute__((noreturn))
void CTGFileImpl::WriteBytes(unsigned char *, int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	9,0(3)\n"
        "mr	30,5\n"
        "lha	0,24(9)\n"
        "lwz	9,28(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "xor	3,3,30\n"
        "subfic	0,3,0\n"
        "adde	3,0,3\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8007D1CC (192 bytes)
// CTGFileImpl::ReadString(char *, int)
__attribute__((noreturn))
void CTGFileImpl::ReadString(char *, int) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	30,16(1)\n"
        "stw	0,28(1)\n"
        "mr	31,3\n"
        "mr	30,4\n"
        "lwz	9,0(31)\n"
        "addi	4,1,8\n"
        "lha	3,88(9)\n"
        "lwz	0,92(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_8007D260\n"
        "lbz	0,8(1)\n"
        "cmpwi	0,255\n"
        "bne	.L_8007D234\n"
        "lwz	9,0(31)\n"
        "addi	4,1,12\n"
        "lha	3,104(9)\n"
        "lwz	0,108(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_8007D238\n"
        ".L_8007D234:\n"
        "stw	0,12(1)\n"
        ".L_8007D238:\n"
        "lwz	9,0(31)\n"
        "mr	4,30\n"
        "lwz	5,12(1)\n"
        "lha	3,72(9)\n"
        "lwz	0,76(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "bne	.L_8007D268\n"
        ".L_8007D260:\n"
        "li	3,0\n"
        "b	.L_8007D278\n"
        ".L_8007D268:\n"
        "lwz	9,12(1)\n"
        "li	0,0\n"
        "li	3,1\n"
        "stbx	0,30,9\n"
        ".L_8007D278:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	30,16(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

