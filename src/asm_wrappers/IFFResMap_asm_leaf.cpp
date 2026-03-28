#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for IFFResMap (stub_classes.h)
// 2 functions, 180 bytes

// 0x800BCE10 (112 bytes)
// IFFResMap::UpdateOffset(int, int)
__attribute__((noreturn))
void IFFResMap::UpdateOffset(int, int) {
    __asm__ __volatile__(
        "mr.	5,5\n"
        "bge	.L_800BCE30\n"
        "li	3,0\n"
        "blr\n"
        ".L_800BCE20:\n"
        "subf	0,5,0\n"
        "li	3,1\n"
        "stw	0,0(9)\n"
        "blr\n"
        ".L_800BCE30:\n"
        "lwz	9,4(3)\n"
        "lwz	3,0(3)\n"
        "cmpw	3,9\n"
        "beq	.L_800BCE78\n"
        "mr	10,9\n"
        ".L_800BCE44:\n"
        "lwz	9,0(3)\n"
        "lwz	11,4(3)\n"
        "cmpw	9,11\n"
        "beq	.L_800BCE6C\n"
        ".L_800BCE54:\n"
        "lwz	0,0(9)\n"
        "cmpw	0,4\n"
        "beq	.L_800BCE20\n"
        "addi	9,9,88\n"
        "cmpw	9,11\n"
        "bne	.L_800BCE54\n"
        ".L_800BCE6C:\n"
        "addi	3,3,24\n"
        "cmpw	3,10\n"
        "bne	.L_800BCE44\n"
        ".L_800BCE78:\n"
        "li	3,0\n"
        "blr\n"
    );
}

// 0x800BD988 (68 bytes)
// IFFResMap::GetIndexedType(int)
__attribute__((noreturn))
void IFFResMap::GetIndexedType(int) {
    __asm__ __volatile__(
        "mr.	4,4\n"
        "ble	.L_800BD9C4\n"
        "lwz	11,0(3)\n"
        "lis	9,-21846\n"
        "lwz	0,4(3)\n"
        "ori	9,9,43691\n"
        "subf	0,11,0\n"
        "mullw	0,0,9\n"
        "srawi	0,0,3\n"
        "cmpw	4,0\n"
        "bgt	.L_800BD9C4\n"
        "mulli	9,4,24\n"
        "add	9,11,9\n"
        "lwz	3,-8(9)\n"
        "blr\n"
        ".L_800BD9C4:\n"
        "li	3,0\n"
        "blr\n"
    );
}

