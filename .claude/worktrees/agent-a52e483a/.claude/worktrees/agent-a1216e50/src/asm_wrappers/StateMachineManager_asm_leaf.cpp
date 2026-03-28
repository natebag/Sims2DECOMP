#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for StateMachineManager (stub_classes.h)
// 3 functions, 308 bytes

// 0x800967A4 (108 bytes)
// StateMachineManager::UpdateMachine(float)
__attribute__((noreturn))
void StateMachineManager::UpdateMachine(float) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stfd	31,16(1)\n"
        "stmw	30,8(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "fmr	31,1\n"
        "lwz	31,0(30)\n"
        "b	.L_800967EC\n"
        ".L_800967C8:\n"
        "lwz	11,0(31)\n"
        "fmr	1,31\n"
        "addi	31,31,4\n"
        "lwz	9,24(11)\n"
        "lwz	0,44(9)\n"
        "lha	3,40(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        ".L_800967EC:\n"
        "lwz	0,4(30)\n"
        "cmpw	31,0\n"
        "bne	.L_800967C8\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "lfd	31,16(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x8009683C (100 bytes)
// StateMachineManager::DrawMachine(ERC *)
__attribute__((noreturn))
void StateMachineManager::DrawMachine(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "mr	29,4\n"
        "lwz	31,0(30)\n"
        "b	.L_80096880\n"
        ".L_8009685C:\n"
        "lwz	11,0(31)\n"
        "mr	4,29\n"
        "addi	31,31,4\n"
        "lwz	9,24(11)\n"
        "lwz	0,52(9)\n"
        "lha	3,48(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        ".L_80096880:\n"
        "lwz	0,4(30)\n"
        "cmpw	31,0\n"
        "bne	.L_8009685C\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x800968A0 (100 bytes)
// StateMachineManager::DrawTopmostMachine(ERC *)
__attribute__((noreturn))
void StateMachineManager::DrawTopmostMachine(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "mr	29,4\n"
        "lwz	31,0(30)\n"
        "b	.L_800968E4\n"
        ".L_800968C0:\n"
        "lwz	11,0(31)\n"
        "mr	4,29\n"
        "addi	31,31,4\n"
        "lwz	9,24(11)\n"
        "lwz	0,60(9)\n"
        "lha	3,56(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        ".L_800968E4:\n"
        "lwz	0,4(30)\n"
        "cmpw	31,0\n"
        "bne	.L_800968C0\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

