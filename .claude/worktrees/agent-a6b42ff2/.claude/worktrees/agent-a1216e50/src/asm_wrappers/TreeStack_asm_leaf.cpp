#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for TreeStack (stub_classes.h)
// 1 functions, 124 bytes

// 0x80149048 (124 bytes)
// TreeStack::Pop(void)
__attribute__((noreturn))
void TreeStack::Pop(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "addi	31,3,8\n"
        "lwz	9,8(3)\n"
        "lwz	0,4(31)\n"
        "subf	0,9,0\n"
        "srwi.	9,0,2\n"
        "bne	.L_801490A4\n"
        "lwz	11,24(3)\n"
        "li	9,1\n"
        "stw	9,-24512(13)\n"
        "li	0,1001\n"
        "sth	0,52(11)\n"
        "li	4,1001\n"
        "lwz	11,24(3)\n"
        "lwz	9,64(11)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801490A4:\n"
        "lwz	9,4(31)\n"
        "addi	9,9,-4\n"
        "stw	9,4(31)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

