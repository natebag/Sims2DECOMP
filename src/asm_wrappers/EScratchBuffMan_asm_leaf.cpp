#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EScratchBuffMan (stub_classes.h)
// 2 functions, 272 bytes

// 0x80328020 (184 bytes)
// EScratchBuffMan::TryAcquireBuffer(EScratchBuffUser *, char *, int)
__attribute__((noreturn))
void EScratchBuffMan::TryAcquireBuffer(EScratchBuffUser *, char *, int) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	28,8(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "mr	31,4\n"
        "lwz	0,8(30)\n"
        "mr	29,5\n"
        "mr	28,6\n"
        "cmpw	31,0\n"
        "bne	.L_8032806C\n"
        "lwz	9,0(31)\n"
        "li	5,0\n"
        "lwz	4,12(30)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8032806C:\n"
        "lwz	0,8(30)\n"
        "cmpwi	0,0\n"
        "beq	.L_80328098\n"
        "lwz	9,0(31)\n"
        "li	4,0\n"
        "li	5,2\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80328098:\n"
        "stw	29,0(30)\n"
        "li	5,1\n"
        "stw	28,4(30)\n"
        "stw	31,8(30)\n"
        "lwz	4,12(30)\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	28,8(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x803280D8 (88 bytes)
// EScratchBuffMan::ReleaseBuffer(EScratchBuffUser *)
__attribute__((noreturn))
void EScratchBuffMan::ReleaseBuffer(EScratchBuffUser *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	11,8(30)\n"
        "lwz	9,0(11)\n"
        "lwz	0,28(9)\n"
        "lha	3,24(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "li	3,1\n"
        "stw	0,4(30)\n"
        "stw	0,8(30)\n"
        "stw	0,0(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

