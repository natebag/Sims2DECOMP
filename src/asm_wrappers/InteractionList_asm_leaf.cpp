#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for InteractionList (stub_classes.h)
// 1 functions, 112 bytes

// 0x80113280 (112 bytes)
// InteractionList::clear(void)
__attribute__((noreturn))
void InteractionList::clear(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	31,0(30)\n"
        ".L_80113298:\n"
        "cmpwi	31,0\n"
        "beq	.L_801132D0\n"
        "mr	11,31\n"
        "lwz	31,0(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80113298\n"
        "lwz	9,64(11)\n"
        "li	4,3\n"
        "lha	3,8(9)\n"
        "lwz	0,12(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_80113298\n"
        ".L_801132D0:\n"
        "li	0,0\n"
        "stw	0,0(30)\n"
        "stw	0,4(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

