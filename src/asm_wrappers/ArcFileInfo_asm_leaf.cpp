#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ArcFileInfo (stub_classes.h)
// 1 functions, 120 bytes

// 0x80321760 (120 bytes)
// ArcFileInfo::OnValidated(void)
__attribute__((noreturn))
void ArcFileInfo::OnValidated(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	9,-22652(13)\n"
        "mr	31,3\n"
        "lwz	4,4(31)\n"
        "lwz	11,0(9)\n"
        "lha	3,160(11)\n"
        "lwz	0,164(11)\n"
        "add	3,9,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr.	3,3\n"
        "beq	.L_803217C4\n"
        "lwz	11,-22652(13)\n"
        "li	0,1\n"
        "stw	0,16(31)\n"
        "mr	4,3\n"
        "lwz	9,0(11)\n"
        "lha	3,176(9)\n"
        "lwz	0,180(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_803217C4:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

