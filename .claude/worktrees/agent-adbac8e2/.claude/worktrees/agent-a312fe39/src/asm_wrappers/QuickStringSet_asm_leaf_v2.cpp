#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for QuickStringSet (stub_classes.h)
// 3 functions, 272 bytes

// 0x800A7C60 (68 bytes)
// QuickStringSet::LoadFromDataID(ObjectDataID &)
__attribute__((noreturn))
void QuickStringSet::LoadFromDataID(ObjectDataID &) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,0(3)\n"
        "lha	5,4(4)\n"
        "lha	0,232(9)\n"
        "lwz	9,236(9)\n"
        "add	3,3,0\n"
        "lwz	4,0(4)\n"
        "mtlr	9\n"
        "blrl\n"
        "subfic	0,3,0\n"
        "adde	3,0,3\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x800A7CD4 (112 bytes)
// QuickStringSet::QueryInterface(unsigned int, void **)
__attribute__((noreturn))
void QuickStringSet::QueryInterface(unsigned int, void **) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,5\n"
        "beq	.L_800A7D2C\n"
        "cmpwi	4,1\n"
        "beq	.L_800A7D08\n"
        "lis	0,27587\n"
        "ori	0,0,31685\n"
        "cmpw	4,0\n"
        "bne	.L_800A7D2C\n"
        ".L_800A7D08:\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	31,0(30)\n"
        "li	3,1\n"
        "b	.L_800A7D30\n"
        ".L_800A7D2C:\n"
        "li	3,0\n"
        ".L_800A7D30:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x800A7D58 (92 bytes)
// QuickStringSet::Release(void)
__attribute__((noreturn))
void QuickStringSet::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,16(11)\n"
        "addi	3,9,-1\n"
        "stw	3,16(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_800A7DA4\n"
        "cmpwi	11,0\n"
        "beq	.L_800A7DA0\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,96(9)\n"
        "lwz	0,100(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800A7DA0:\n"
        "li	3,0\n"
        ".L_800A7DA4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

