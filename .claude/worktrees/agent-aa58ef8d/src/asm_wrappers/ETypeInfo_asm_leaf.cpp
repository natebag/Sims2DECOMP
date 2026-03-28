#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ETypeInfo (stub_classes.h)
// 1 functions, 136 bytes

// 0x802D5954 (136 bytes)
// ETypeInfo::Insert(void)
__attribute__((noreturn))
void ETypeInfo::Insert(void) {
    __asm__ __volatile__(
        "lwz	0,-26844(13)\n"
        "li	10,0\n"
        "lwz	9,-26848(13)\n"
        "stw	0,36(3)\n"
        "stw	3,-26844(13)\n"
        "cmpwi	9,0\n"
        "beq	.L_802D59A0\n"
        "lwz	11,16(3)\n"
        ".L_802D5974:\n"
        "lwz	0,16(9)\n"
        "cmpw	0,11\n"
        "beqlr\n"
        "mr	10,9\n"
        "cmplw	11,0\n"
        "bge	.L_802D5994\n"
        "lwz	9,28(10)\n"
        "b	.L_802D5998\n"
        ".L_802D5994:\n"
        "lwz	9,32(10)\n"
        ".L_802D5998:\n"
        "cmpwi	9,0\n"
        "bne	.L_802D5974\n"
        ".L_802D59A0:\n"
        "cmpwi	10,0\n"
        "beq	.L_802D59C8\n"
        "lwz	9,16(3)\n"
        "lwz	0,16(10)\n"
        "cmplw	9,0\n"
        "bge	.L_802D59C0\n"
        "stw	3,28(10)\n"
        "b	.L_802D59CC\n"
        ".L_802D59C0:\n"
        "stw	3,32(10)\n"
        "b	.L_802D59CC\n"
        ".L_802D59C8:\n"
        "stw	3,-26848(13)\n"
        ".L_802D59CC:\n"
        "li	0,0\n"
        "stw	0,28(3)\n"
        "stw	0,32(3)\n"
        "blr\n"
    );
}

