#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EBitArray (stub_classes.h)
// 5 functions, 500 bytes

// 0x802DF72C (84 bytes)
// EBitArray::Deallocate(void)
__attribute__((noreturn))
void EBitArray::Deallocate(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	9,16(30)\n"
        "lwz	4,0(30)\n"
        "lwz	0,28(9)\n"
        "lha	3,24(9)\n"
        "mtlr	0\n"
        "add	3,30,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,4(30)\n"
        "stw	0,0(30)\n"
        "stw	0,8(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x802E02A0 (140 bytes)
// EBitArray::ToleranceToSignedBits(float)
__attribute__((noreturn))
void EBitArray::ToleranceToSignedBits(float) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "li	0,1\n"
        "xoris	0,0,32768\n"
        "lis	11,17200\n"
        "stw	0,12(1)\n"
        "lis	9,-32702\n"
        "lfd	13,-6440(9)\n"
        "li	3,2\n"
        "stw	11,8(1)\n"
        "lfd	0,8(1)\n"
        "fsub	0,0,13\n"
        "frsp	0,0\n"
        "fcmpu	cr0,0,1\n"
        "cror	so,eq,lt\n"
        "bso	.L_802E0324\n"
        "fmr	12,0\n"
        "li	8,1\n"
        ".L_802E02E4:\n"
        "addi	3,3,1\n"
        "cmpwi	3,31\n"
        "bgt	.L_802E0324\n"
        "addi	9,3,-1\n"
        "slw	9,8,9\n"
        "addi	9,9,-1\n"
        "xoris	0,9,32768\n"
        "stw	0,12(1)\n"
        "stw	11,8(1)\n"
        "lfd	0,8(1)\n"
        "fsub	0,0,13\n"
        "frsp	0,0\n"
        "fdivs	0,12,0\n"
        "fcmpu	cr0,0,1\n"
        "cror	so,eq,lt\n"
        "bns	.L_802E02E4\n"
        ".L_802E0324:\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x802E048C (128 bytes)
// EBitArray::FloatToUnsignedBits(float, int)
__attribute__((noreturn))
void EBitArray::FloatToUnsignedBits(float, int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "li	9,1\n"
        "slw	9,9,4\n"
        "lis	0,17200\n"
        "addi	9,9,-1\n"
        "lis	11,-32702\n"
        "xoris	9,9,32768\n"
        "lfd	13,-6400(11)\n"
        "stw	9,12(1)\n"
        "lis	11,-32702\n"
        "lfs	12,-6392(11)\n"
        "lis	9,-32702\n"
        "stw	0,8(1)\n"
        "lfs	11,-6388(9)\n"
        "lfd	0,8(1)\n"
        "fsub	0,0,13\n"
        "frsp	0,0\n"
        "fmadds	13,1,0,12\n"
        "fcmpu	cr0,13,11\n"
        "bge	.L_802E04E4\n"
        "fmr	12,11\n"
        "b	.L_802E04F4\n"
        ".L_802E04E4:\n"
        "fmr	12,13\n"
        "fcmpu	cr0,13,0\n"
        "ble	.L_802E04F4\n"
        "fmr	12,0\n"
        ".L_802E04F4:\n"
        "fmr	0,12\n"
        "fctiwz	13,0\n"
        "stfd	13,8(1)\n"
        "lwz	3,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x802E050C (76 bytes)
// EBitArray::SignedBitsToFloatScaler(int)
__attribute__((noreturn))
void EBitArray::SignedBitsToFloatScaler(int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "addi	4,4,-1\n"
        "li	9,1\n"
        "slw	9,9,4\n"
        "addi	9,9,-1\n"
        "lis	0,17200\n"
        "xoris	9,9,32768\n"
        "lis	10,-32702\n"
        "stw	9,12(1)\n"
        "lis	8,-32702\n"
        "lfd	0,-6384(10)\n"
        "stw	0,8(1)\n"
        "lfs	13,-6376(8)\n"
        "lfd	1,8(1)\n"
        "fsub	1,1,0\n"
        "frsp	1,1\n"
        "fdivs	1,13,1\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x802E0558 (72 bytes)
// EBitArray::UnsignedBitsToFloatScaler(int)
__attribute__((noreturn))
void EBitArray::UnsignedBitsToFloatScaler(int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "li	9,1\n"
        "slw	9,9,4\n"
        "lis	0,17200\n"
        "addi	9,9,-1\n"
        "lis	11,-32702\n"
        "xoris	9,9,32768\n"
        "lfd	0,-6368(11)\n"
        "stw	9,12(1)\n"
        "lis	11,-32702\n"
        "lfs	13,-6360(11)\n"
        "stw	0,8(1)\n"
        "lfd	1,8(1)\n"
        "fsub	1,1,0\n"
        "frsp	1,1\n"
        "fdivs	1,13,1\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

