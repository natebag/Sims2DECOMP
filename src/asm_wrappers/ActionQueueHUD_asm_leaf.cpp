#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ActionQueueHUD (stub_classes.h)
// 2 functions, 244 bytes

// 0x80184FE0 (136 bytes)
// ActionQueueHUD::OnUserCancelledAction(unsigned int)
__attribute__((noreturn))
void ActionQueueHUD::OnUserCancelledAction(unsigned int) {
    __asm__ __volatile__(
        "lwz	0,336(3)\n"
        "li	9,0\n"
        "cmplw	9,0\n"
        "bge	.L_80185020\n"
        "mr	10,0\n"
        "addi	11,3,168\n"
        ".L_80184FF8:\n"
        "lwz	0,0(11)\n"
        "addi	11,11,20\n"
        "cmpw	0,4\n"
        "bne	.L_80185014\n"
        "mr	11,9\n"
        "lwz	0,336(3)\n"
        "b	.L_80185028\n"
        ".L_80185014:\n"
        "addi	9,9,1\n"
        "cmplw	9,10\n"
        "blt	.L_80184FF8\n"
        ".L_80185020:\n"
        "lwz	11,336(3)\n"
        "mr	0,11\n"
        ".L_80185028:\n"
        "cmplw	11,0\n"
        "bgelr\n"
        "mulli	9,11,20\n"
        "li	10,1\n"
        "mr	11,9\n"
        "add	9,9,3\n"
        "lbz	0,173(9)\n"
        "cmpwi	0,0\n"
        "bne	.L_80185050\n"
        "li	10,0\n"
        ".L_80185050:\n"
        "cmpwi	10,0\n"
        "bnelr\n"
        "add	9,11,3\n"
        "li	0,1\n"
        "stb	0,173(9)\n"
        "blr\n"
    );
}

// 0x80185870 (108 bytes)
// ActionQueueHUD::GetPlayerSim(void) const
__attribute__((noreturn))
void ActionQueueHUD::GetPlayerSim(void) const {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	0,788(3)\n"
        "lis	9,-32697\n"
        "addi	9,9,24012\n"
        "slwi	0,0,2\n"
        "addi	9,9,188\n"
        "lwzx	31,9,0\n"
        "cmpwi	31,0\n"
        "beq	.L_801858C4\n"
        "lwz	9,4(31)\n"
        "lha	3,776(9)\n"
        "lwz	0,780(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "bne	.L_801858C4\n"
        "li	31,0\n"
        ".L_801858C4:\n"
        "mr	3,31\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

