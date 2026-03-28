#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EHouse (stub_classes.h)
// 1 functions, 128 bytes

// 0x80024828 (128 bytes)
// EHouse::WeatherChanging(void)
__attribute__((noreturn))
void EHouse::WeatherChanging(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	11,-21496(13)\n"
        "mr	29,3\n"
        "li	4,0\n"
        "lwz	9,0(11)\n"
        "lwz	0,52(9)\n"
        "lha	3,48(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	11,-21496(13)\n"
        "mr	30,3\n"
        "li	4,5\n"
        "lwz	9,0(11)\n"
        "lwz	0,52(9)\n"
        "lha	3,48(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "mulli	30,30,60\n"
        "li	0,1\n"
        "stw	0,56(29)\n"
        "add	30,30,3\n"
        "stw	30,52(29)\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

