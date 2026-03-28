#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ActionMenu (stub_classes.h)
// 1 functions, 108 bytes

// 0x80184520 (108 bytes)
// ActionMenu::GetPlayerSim(void) const
__attribute__((noreturn))
void ActionMenu::GetPlayerSim(void) const {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	0,168(3)\n"
        "lis	9,-32697\n"
        "addi	9,9,24012\n"
        "slwi	0,0,2\n"
        "addi	9,9,188\n"
        "lwzx	31,9,0\n"
        "cmpwi	31,0\n"
        "beq	.L_80184574\n"
        "lwz	9,4(31)\n"
        "lha	3,776(9)\n"
        "lwz	0,780(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "bne	.L_80184574\n"
        "li	31,0\n"
        ".L_80184574:\n"
        "mr	3,31\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

