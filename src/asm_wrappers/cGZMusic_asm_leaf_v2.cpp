#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cGZMusic (stub_classes.h)
// 3 functions, 304 bytes

// 0x800BAC14 (128 bytes)
// cGZMusic::Release(void)
__attribute__((noreturn))
void cGZMusic::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	3,4(31)\n"
        "cmpwi	3,1\n"
        "bne	.L_800BAC78\n"
        "lwz	9,0(31)\n"
        "lha	3,48(9)\n"
        "lwz	0,52(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	31,0\n"
        "beq	.L_800BAC70\n"
        "lwz	9,0(31)\n"
        "li	4,3\n"
        "lha	3,152(9)\n"
        "lwz	0,156(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800BAC70:\n"
        "li	3,0\n"
        "b	.L_800BAC80\n"
        ".L_800BAC78:\n"
        "addi	3,3,-1\n"
        "stw	3,4(31)\n"
        ".L_800BAC80:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x800BAE54 (88 bytes)
// cGZMusic::Unpause(void)
__attribute__((noreturn))
void cGZMusic::Unpause(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,-24468(13)\n"
        "lwz	0,1036(9)\n"
        "cmpw	0,3\n"
        "bne	.L_800BAE98\n"
        "lwz	11,-26564(13)\n"
        "lwz	9,0(11)\n"
        "lwz	0,92(9)\n"
        "lha	3,88(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,-24468(13)\n"
        "li	0,0\n"
        "stw	0,1048(9)\n"
        ".L_800BAE98:\n"
        "li	3,1\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x800BB19C (88 bytes)
// cGZMusic::reset(void)
__attribute__((noreturn))
void cGZMusic::reset(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,-24468(13)\n"
        "lwz	10,1036(9)\n"
        "cmpw	10,3\n"
        "bne	.L_800BB1E4\n"
        "lwz	11,-26564(13)\n"
        "li	0,0\n"
        "stw	0,8(10)\n"
        "stw	0,1048(9)\n"
        "stw	0,1036(9)\n"
        "lwz	9,0(11)\n"
        "lha	3,72(9)\n"
        "lwz	0,76(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_800BB1E4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

