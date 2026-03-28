#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cXObject (stub_classes.h)
// 2 functions, 144 bytes

// 0x800DB954 (76 bytes)
// cXObject::SetFreeWill(bool)
__attribute__((noreturn))
void cXObject::SetFreeWill(bool) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-21496(13)\n"
        "stw	3,-31912(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_800DB990\n"
        "lwz	9,0(11)\n"
        "li	4,30\n"
        "lha	5,-31910(13)\n"
        "lha	3,56(9)\n"
        "lwz	0,60(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800DB990:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x800EA9BC (68 bytes)
// cXObject::CAST_IMPL(void)
__attribute__((noreturn))
void cXObject::CAST_IMPL(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr.	11,3\n"
        "bne	.L_800EA9D8\n"
        "li	3,0\n"
        "b	.L_800EA9F0\n"
        ".L_800EA9D8:\n"
        "lwz	9,4(11)\n"
        "lha	3,1312(9)\n"
        "lwz	0,1316(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800EA9F0:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

