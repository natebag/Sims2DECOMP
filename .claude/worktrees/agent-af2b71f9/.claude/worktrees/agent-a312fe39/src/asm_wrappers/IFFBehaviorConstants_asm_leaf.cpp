#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for IFFBehaviorConstants (stub_classes.h)
// 2 functions, 204 bytes

// 0x8015A5A4 (112 bytes)
// IFFBehaviorConstants::QueryInterface(unsigned int, void **)
__attribute__((noreturn))
void IFFBehaviorConstants::QueryInterface(unsigned int, void **) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,5\n"
        "beq	.L_8015A5FC\n"
        "cmpwi	4,1\n"
        "beq	.L_8015A5D8\n"
        "lis	0,-5160\n"
        "ori	0,0,51892\n"
        "cmpw	4,0\n"
        "bne	.L_8015A5FC\n"
        ".L_8015A5D8:\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	31,0(30)\n"
        "li	3,1\n"
        "b	.L_8015A600\n"
        ".L_8015A5FC:\n"
        "li	3,0\n"
        ".L_8015A600:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8015A628 (92 bytes)
// IFFBehaviorConstants::Release(void)
__attribute__((noreturn))
void IFFBehaviorConstants::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,96(11)\n"
        "addi	3,9,-1\n"
        "stw	3,96(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_8015A674\n"
        "cmpwi	11,0\n"
        "beq	.L_8015A670\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,112(9)\n"
        "lwz	0,116(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8015A670:\n"
        "li	3,0\n"
        ".L_8015A674:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

