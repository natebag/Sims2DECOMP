#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for StateMachineStatus (stub_classes.h)
// 2 functions, 264 bytes

// 0x80096424 (180 bytes)
// StateMachineStatus::SetState(StateMachineState *)
__attribute__((noreturn))
void StateMachineStatus::SetState(StateMachineState *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "mr	31,4\n"
        "lwz	11,0(30)\n"
        "cmpw	31,11\n"
        "bne	.L_8009646C\n"
        "cmpwi	31,0\n"
        "beq	.L_800964C4\n"
        "lwz	9,24(31)\n"
        "lha	3,32(9)\n"
        "lwz	0,36(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_800964C4\n"
        ".L_8009646C:\n"
        "cmpwi	11,0\n"
        "beq	.L_8009648C\n"
        "lwz	9,24(11)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8009648C:\n"
        "lwz	0,0(30)\n"
        "cmpwi	31,0\n"
        "stw	31,0(30)\n"
        "stw	0,8(30)\n"
        "beq	.L_800964C4\n"
        "lwz	9,24(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lis	9,-32706\n"
        "lfs	0,-30516(9)\n"
        "stfs	0,20(30)\n"
        ".L_800964C4:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80096514 (84 bytes)
// StateMachineStatus::ShutdownCurState(void)
__attribute__((noreturn))
void StateMachineStatus::ShutdownCurState(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	11,0(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80096554\n"
        "lwz	9,24(11)\n"
        "lwz	0,28(9)\n"
        "lha	3,24(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,0(31)\n"
        ".L_80096554:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

