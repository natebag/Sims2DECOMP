#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EMovie (stub_classes.h)
// 1 functions, 168 bytes

// 0x80364C24 (168 bytes)
// EMovie::Update(void)
__attribute__((noreturn))
void EMovie::Update(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	9,8(31)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "bne	.L_80364CB8\n"
        "lwz	11,-26392(13)\n"
        "li	4,0\n"
        "lwz	9,0(11)\n"
        "lwz	0,132(9)\n"
        "lha	3,128(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "mr	30,3\n"
        "mr	4,31\n"
        "lwz	9,112(30)\n"
        "lwz	0,596(9)\n"
        "lha	3,592(9)\n"
        "mtlr	0\n"
        "add	3,30,3\n"
        "blrl\n"
        "lwz	11,-26392(13)\n"
        "mr	4,30\n"
        "lwz	9,0(11)\n"
        "lha	3,136(9)\n"
        "lwz	0,140(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80364CB8:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

