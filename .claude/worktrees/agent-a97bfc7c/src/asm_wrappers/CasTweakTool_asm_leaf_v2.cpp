#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CasTweakTool (stub_classes.h)
// 1 functions, 88 bytes

// 0x80175300 (88 bytes)
// CasTweakTool::GetLights(ELights &)
__attribute__((noreturn))
void CasTweakTool::GetLights(ELights &) {
    __asm__ __volatile__(
        "li	9,240\n"
        ".L_80175304:\n"
        "lwz	0,0(3)\n"
        "addic.	9,9,-24\n"
        "stw	0,0(4)\n"
        "lwz	0,4(3)\n"
        "stw	0,4(4)\n"
        "lwz	0,8(3)\n"
        "stw	0,8(4)\n"
        "lwz	0,12(3)\n"
        "stw	0,12(4)\n"
        "lwz	0,16(3)\n"
        "stw	0,16(4)\n"
        "lwz	0,20(3)\n"
        "addi	3,3,24\n"
        "stw	0,20(4)\n"
        "addi	4,4,24\n"
        "bne	.L_80175304\n"
        "lwz	0,0(3)\n"
        "stw	0,0(4)\n"
        "lwz	0,4(3)\n"
        "stw	0,4(4)\n"
        "blr\n"
    );
}

