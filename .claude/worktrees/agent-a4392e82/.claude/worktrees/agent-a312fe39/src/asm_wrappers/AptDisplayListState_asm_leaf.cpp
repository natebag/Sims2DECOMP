#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptDisplayListState (stub_classes.h)
// 1 functions, 92 bytes

// 0x802994A4 (92 bytes)
// AptDisplayListState::RegisterReferences(AptValue *) const
__attribute__((noreturn))
void AptDisplayListState::RegisterReferences(AptValue *) const {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	31,0(3)\n"
        "mr	30,4\n"
        "cmpwi	31,0\n"
        "beq	.L_802994EC\n"
        "lis	29,-32704\n"
        ".L_802994C8:\n"
        "lwz	9,-27024(13)\n"
        "mr	4,31\n"
        "mr	3,30\n"
        "addi	5,29,29692\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	31,84(31)\n"
        "cmpwi	31,0\n"
        "bne	.L_802994C8\n"
        ".L_802994EC:\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

