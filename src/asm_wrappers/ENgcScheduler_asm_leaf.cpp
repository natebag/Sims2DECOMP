#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ENgcScheduler (stub_classes.h)
// 1 functions, 120 bytes

// 0x8034DADC (120 bytes)
// ENgcScheduler::FreeSchedCommand(ESchedCommand *)
__attribute__((noreturn))
void ENgcScheduler::FreeSchedCommand(ESchedCommand *) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "mr	31,3\n"
        "mr	30,4\n"
        "lwz	9,928(31)\n"
        "addi	29,31,928\n"
        "li	4,-1\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,29,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	30,0\n"
        "beq	.L_8034DB28\n"
        "lwz	0,916(31)\n"
        "stw	0,0(30)\n"
        "stw	30,916(31)\n"
        ".L_8034DB28:\n"
        "lwz	9,928(31)\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,29,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

