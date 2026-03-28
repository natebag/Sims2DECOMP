#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for GOLTarget (stub_classes.h)
// 3 functions, 340 bytes

// 0x801EB580 (100 bytes)
// GOLTarget::IsMapGoalUnlocked(int, int, int)
__attribute__((noreturn))
void GOLTarget::IsMapGoalUnlocked(int, int, int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21476(13)\n"
        "li	4,1\n"
        "lwz	9,0(11)\n"
        "lwz	0,292(9)\n"
        "lha	3,288(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(3)\n"
        "lha	0,328(9)\n"
        "lwz	9,332(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "li	3,0\n"
        "beq	.L_801EB5D4\n"
        "li	3,1\n"
        ".L_801EB5D4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801EB5E4 (120 bytes)
// GOLTarget::IsHouseUnlocked(int, int)
__attribute__((noreturn))
void GOLTarget::IsHouseUnlocked(int, int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	3,-21476(13)\n"
        "li	4,1\n"
        "li	31,0\n"
        "lwz	9,0(3)\n"
        "lha	0,288(9)\n"
        "lwz	9,292(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "mr.	11,3\n"
        "beq	.L_801EB644\n"
        "lwz	9,0(11)\n"
        "lha	3,328(9)\n"
        "lwz	0,332(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_801EB644\n"
        "li	31,1\n"
        ".L_801EB644:\n"
        "mr	3,31\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x801EB65C (120 bytes)
// GOLTarget::IsApartmentUnlocked(int, int)
__attribute__((noreturn))
void GOLTarget::IsApartmentUnlocked(int, int) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	3,-21476(13)\n"
        "li	4,1\n"
        "li	31,0\n"
        "lwz	9,0(3)\n"
        "lha	0,288(9)\n"
        "lwz	9,292(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "mr.	11,3\n"
        "beq	.L_801EB6BC\n"
        "lwz	9,0(11)\n"
        "lha	3,328(9)\n"
        "lwz	0,332(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "beq	.L_801EB6BC\n"
        "li	31,1\n"
        ".L_801EB6BC:\n"
        "mr	3,31\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

