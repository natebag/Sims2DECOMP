#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EResourceManager (stub_classes.h)
// 4 functions, 476 bytes

// 0x80325CE8 (164 bytes)
// EResourceManager::ArchiveFileIsUsingHDD(void)
__attribute__((noreturn))
void EResourceManager::ArchiveFileIsUsingHDD(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	30,16(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "li	4,-1\n"
        "stw	30,8(1)\n"
        "lwz	9,0(30)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	9,80(30)\n"
        "cmpwi	9,0\n"
        "bne	.L_80325D4C\n"
        "lwz	3,8(1)\n"
        "lwz	9,0(3)\n"
        "lha	0,24(9)\n"
        "lwz	9,28(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "li	3,0\n"
        "b	.L_80325D78\n"
        ".L_80325D4C:\n"
        "lwz	11,8(1)\n"
        "lwz	30,16(9)\n"
        "lwz	9,0(11)\n"
        "subfic	0,30,0\n"
        "adde	30,0,30\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	3,30\n"
        ".L_80325D78:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	30,16(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x80325D8C (124 bytes)
// EResourceManager::ArchiveFileIsOpen(void)
__attribute__((noreturn))
void EResourceManager::ArchiveFileIsOpen(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	30,16(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "li	4,-1\n"
        "stw	30,8(1)\n"
        "li	31,1\n"
        "lwz	9,0(30)\n"
        "lwz	0,20(9)\n"
        "lha	3,16(9)\n"
        "mtlr	0\n"
        "add	3,30,3\n"
        "blrl\n"
        "lwz	0,80(30)\n"
        "cmpwi	0,0\n"
        "bne	.L_80325DD4\n"
        "li	31,0\n"
        ".L_80325DD4:\n"
        "lwz	3,8(1)\n"
        "lwz	9,0(3)\n"
        "lha	0,24(9)\n"
        "lwz	9,28(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "mr	3,31\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	30,16(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x80325E6C (100 bytes)
// EResourceManager::BinarySearch(unsigned int, unsigned int *, int)
__attribute__((noreturn))
void EResourceManager::BinarySearch(unsigned int, unsigned int *, int) {
    __asm__ __volatile__(
        "mr	10,3\n"
        "mr.	5,5\n"
        "beq	.L_80325EC8\n"
        "addi	5,5,-1\n"
        "li	3,0\n"
        ".L_80325E80:\n"
        "cmpw	3,5\n"
        "bge	.L_80325EB0\n"
        "add	0,3,5\n"
        "srawi	11,0,1\n"
        "slwi	9,11,2\n"
        "lwzx	0,9,4\n"
        "cmplw	0,10\n"
        "bge	.L_80325EA8\n"
        "addi	3,11,1\n"
        "b	.L_80325E80\n"
        ".L_80325EA8:\n"
        "mr	5,11\n"
        "b	.L_80325E80\n"
        ".L_80325EB0:\n"
        "slwi	9,3,2\n"
        "lwzx	0,9,4\n"
        "cmpw	0,10\n"
        "beqlr\n"
        "li	3,-1\n"
        "blr\n"
        ".L_80325EC8:\n"
        "li	3,-1\n"
        "blr\n"
    );
}

// 0x80326814 (88 bytes)
// EResourceManager::ReadData(void *, unsigned int, unsigned int)
__attribute__((noreturn))
void EResourceManager::ReadData(void *, unsigned int, unsigned int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	10,-22652(13)\n"
        "mr	0,4\n"
        "mr	11,5\n"
        "mr	4,3\n"
        "lwz	9,0(10)\n"
        "mr	5,0\n"
        "mr	7,6\n"
        "li	8,1\n"
        "lha	3,120(9)\n"
        "mr	6,11\n"
        "lwz	0,124(9)\n"
        "add	3,10,3\n"
        "li	9,0\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

