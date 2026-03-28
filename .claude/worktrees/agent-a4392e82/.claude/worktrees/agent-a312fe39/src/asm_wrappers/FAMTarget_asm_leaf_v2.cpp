#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for FAMTarget (stub_classes.h)
// 1 functions, 68 bytes

// 0x801B0DB4 (68 bytes)
// FAMTarget::GetNumberOfFamilyMembers(Family *)
__attribute__((noreturn))
void FAMTarget::GetNumberOfFamilyMembers(Family *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr.	4,4\n"
        "beq	.L_801B0DE4\n"
        "lwz	9,0(4)\n"
        "lha	3,48(9)\n"
        "lwz	0,52(9)\n"
        "add	3,4,3\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_801B0DE8\n"
        ".L_801B0DE4:\n"
        "li	3,0\n"
        ".L_801B0DE8:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

