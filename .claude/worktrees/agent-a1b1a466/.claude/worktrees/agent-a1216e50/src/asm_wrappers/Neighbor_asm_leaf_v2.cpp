#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for Neighbor (stub_classes.h)
// 1 functions, 172 bytes

// 0x800CA424 (172 bytes)
// Neighbor::AdjustRelationship(Neighbor *, int)
__attribute__((noreturn))
void Neighbor::AdjustRelationship(Neighbor *, int) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "mr	29,5\n"
        "mr.	4,4\n"
        "beq	.L_800CA4BC\n"
        "lwz	3,16(30)\n"
        "lha	31,4(4)\n"
        "lwz	9,0(3)\n"
        "mr	4,31\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "bne	.L_800CA494\n"
        "lwz	3,16(30)\n"
        "mr	4,31\n"
        "li	5,1\n"
        "lwz	9,0(3)\n"
        "lha	0,40(9)\n"
        "lwz	9,44(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        ".L_800CA494:\n"
        "lwz	3,16(30)\n"
        "mr	4,31\n"
        "mr	6,29\n"
        "li	5,0\n"
        "lwz	9,0(3)\n"
        "lha	0,72(9)\n"
        "lwz	9,76(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        ".L_800CA4BC:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

