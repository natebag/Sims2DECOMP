#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptGC (stub_classes.h)
// 1 functions, 72 bytes

// 0x8029C654 (72 bytes)
// AptGC::sReferenceRegistrationCb(AptValue *, AptValue *, char *)
__attribute__((noreturn))
void AptGC::sReferenceRegistrationCb(AptValue *, AptValue *, char *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,0(4)\n"
        "andis.	9,0,16384\n"
        "bne	.L_8029C68C\n"
        "oris	0,0,16384\n"
        "lwz	9,8(4)\n"
        "stw	0,0(4)\n"
        "lha	3,112(9)\n"
        "lwz	0,116(9)\n"
        "add	3,4,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8029C68C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

