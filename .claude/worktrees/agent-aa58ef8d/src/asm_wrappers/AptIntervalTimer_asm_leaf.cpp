#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for AptIntervalTimer (stub_classes.h)
// 1 functions, 144 bytes

// 0x80285640 (144 bytes)
// AptIntervalTimer::cleanParams(void)
__attribute__((noreturn))
void AptIntervalTimer::cleanParams(void) {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "mflr	0\n"
        "stmw	27,12(1)\n"
        "stw	0,36(1)\n"
        "mr	31,3\n"
        "lwz	0,20(31)\n"
        "cmpwi	0,0\n"
        "ble	.L_802856BC\n"
        "mr	30,0\n"
        "addi	29,31,20\n"
        "lis	27,-32704\n"
        "lis	28,-32704\n"
        ".L_80285670:\n"
        "lwz	11,20(31)\n"
        "addi	4,27,10768\n"
        "lwz	0,8(29)\n"
        "addi	5,28,10808\n"
        "slwi	11,11,2\n"
        "li	6,126\n"
        "add	11,11,0\n"
        "lwz	10,-4(11)\n"
        "lwz	9,8(10)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,10,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	9,20(31)\n"
        "addic.	30,30,-1\n"
        "addi	9,9,-1\n"
        "stw	9,20(31)\n"
        "bne	.L_80285670\n"
        ".L_802856BC:\n"
        "lwz	0,36(1)\n"
        "mtlr	0\n"
        "lmw	27,12(1)\n"
        "addi	1,1,32\n"
        "blr\n"
    );
}

