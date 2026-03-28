#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptCIH (stub_classes.h)
// 5 functions, 552 bytes

// 0x8028FFEC (80 bytes)
// AptCIH::PreDestroy(void)
__attribute__((noreturn))
void AptCIH::PreDestroy(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,76(3)\n"
        "cmpwi	11,0\n"
        "beq	.L_8029002C\n"
        "lis	0,-17747\n"
        "ori	0,0,61453\n"
        "cmpw	11,0\n"
        "beq	.L_8029002C\n"
        "lwz	9,20(11)\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8029002C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x8029003C (156 bytes)
// AptCIH::DestroyGCPointers(void)
__attribute__((noreturn))
void AptCIH::DestroyGCPointers(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	11,76(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80290084\n"
        "lis	0,-17747\n"
        "ori	0,0,61453\n"
        "cmpw	11,0\n"
        "beq	.L_80290084\n"
        "lwz	9,20(11)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80290084:\n"
        "lwz	11,72(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_802900BC\n"
        "lwz	9,8(11)\n"
        "lis	4,-32704\n"
        "lis	5,-32704\n"
        "addi	4,4,22884\n"
        "lha	3,16(9)\n"
        "addi	5,5,22800\n"
        "lwz	0,20(9)\n"
        "li	6,208\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_802900BC:\n"
        "li	0,0\n"
        "stw	0,72(31)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80292B58 (76 bytes)
// AptCIH::SetEventHandler(int)
__attribute__((noreturn))
void AptCIH::SetEventHandler(int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	9,8(3)\n"
        "mr	30,4\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,16(3)\n"
        "or	0,0,30\n"
        "stw	0,16(3)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80292BA4 (76 bytes)
// AptCIH::RemoveEventHandler(int)
__attribute__((noreturn))
void AptCIH::RemoveEventHandler(int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	9,8(3)\n"
        "mr	30,4\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,16(3)\n"
        "andc	30,0,30\n"
        "stw	30,16(3)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80292BF0 (164 bytes)
// AptCIH::HasEvent(int)
__attribute__((noreturn))
void AptCIH::HasEvent(int) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	28,8(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "mr	31,4\n"
        "lwz	9,8(30)\n"
        "li	28,0\n"
        "lwz	0,36(9)\n"
        "lha	3,32(9)\n"
        "mtlr	0\n"
        "add	3,30,3\n"
        "blrl\n"
        "lwz	9,76(30)\n"
        "mr	29,3\n"
        "lwz	0,28(9)\n"
        "srawi	0,0,8\n"
        "and.	9,0,31\n"
        "bne	.L_80292C78\n"
        "lwz	11,8(29)\n"
        "cmpwi	11,0\n"
        "beq	.L_80292C6C\n"
        "lwz	9,8(11)\n"
        "lwz	0,36(9)\n"
        "lha	3,32(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	0,16(3)\n"
        "and.	9,0,31\n"
        "bne	.L_80292C78\n"
        ".L_80292C6C:\n"
        "lwz	0,16(29)\n"
        "and.	9,0,31\n"
        "beq	.L_80292C7C\n"
        ".L_80292C78:\n"
        "li	28,1\n"
        ".L_80292C7C:\n"
        "mr	3,28\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	28,8(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

