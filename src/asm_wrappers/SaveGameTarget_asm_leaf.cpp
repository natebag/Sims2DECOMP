#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for SaveGameTarget (stub_classes.h)
// 1 functions, 76 bytes

// 0x8018FEF0 (76 bytes)
// SaveGameTarget::BGCall_SaveGame(void)
__attribute__((noreturn))
void SaveGameTarget::BGCall_SaveGame(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-22756(13)\n"
        "mr	5,3\n"
        "lis	4,-32743\n"
        "li	0,0\n"
        "lwz	9,0(11)\n"
        "addi	4,4,-196\n"
        "lha	3,72(9)\n"
        "lwz	9,76(9)\n"
        "add	3,11,3\n"
        "stw	0,-21480(13)\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

