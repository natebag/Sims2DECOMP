#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for MUStatesFormat (stub_classes.h)
// 1 functions, 72 bytes

// 0x80091764 (72 bytes)
// MUStatesFormat::Draw(ERC *)
__attribute__((noreturn))
void MUStatesFormat::Draw(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,32(3)\n"
        "cmpwi	0,1\n"
        "bne	.L_8009179C\n"
        "lwz	11,8(3)\n"
        "lwz	10,152(11)\n"
        "lwz	9,128(10)\n"
        "lha	3,48(9)\n"
        "lwz	0,52(9)\n"
        "add	3,10,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8009179C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

