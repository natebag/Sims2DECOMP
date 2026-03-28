#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for MMUTarget (stub_classes.h)
// 2 functions, 268 bytes

// 0x801C77CC (80 bytes)
// MMUTarget::OnCancelKeyPressed(char *, char *)
__attribute__((noreturn))
void MMUTarget::OnCancelKeyPressed(char *, char *) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	0,140(11)\n"
        "cmpwi	0,0\n"
        "bne	.L_801C780C\n"
        "lwz	9,128(11)\n"
        "lis	4,-32705\n"
        "addi	4,4,9956\n"
        "li	5,0\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801C780C:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801C8364 (188 bytes)
// MMUTarget::SetCurrentChoice(char *)
__attribute__((noreturn))
void MMUTarget::SetCurrentChoice(char *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr	30,4\n"
        "lwz	0,176(31)\n"
        "cmpwi	0,1\n"
        "bne	.L_801C83AC\n"
        "lwz	9,128(31)\n"
        "lis	4,-32705\n"
        "addi	4,4,10332\n"
        "mr	5,30\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801C83AC:\n"
        "lwz	0,176(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_801C83DC\n"
        "lwz	9,128(31)\n"
        "lis	4,-32705\n"
        "addi	4,4,10356\n"
        "mr	5,30\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801C83DC:\n"
        "lwz	0,176(31)\n"
        "cmpwi	0,4\n"
        "bne	.L_801C840C\n"
        "lwz	9,128(31)\n"
        "lis	4,-32705\n"
        "addi	4,4,10384\n"
        "mr	5,30\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801C840C:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

