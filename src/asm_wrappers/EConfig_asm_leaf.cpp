#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EConfig (stub_classes.h)
// 1 functions, 164 bytes

// 0x8035ADCC (164 bytes)
// EConfig::GetS(char *, int, EFile *)
__attribute__((noreturn))
void EConfig::GetS(char *, int, EFile *) {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "mflr	0\n"
        "stmw	28,16(1)\n"
        "stw	0,36(1)\n"
        "mr	28,3\n"
        "mr	29,5\n"
        "mr	31,28\n"
        "mr.	30,4\n"
        "bgt	.L_8035AE18\n"
        ".L_8035ADF0:\n"
        "li	3,0\n"
        "b	.L_8035AE5C\n"
        ".L_8035ADF8:\n"
        "lbz	9,8(1)\n"
        "extsb	0,9\n"
        "cmpwi	0,13\n"
        "beq	.L_8035AE18\n"
        "cmpwi	0,10\n"
        "beq	.L_8035AE50\n"
        "stb	9,0(31)\n"
        "addi	31,31,1\n"
        ".L_8035AE18:\n"
        "addic.	30,30,-1\n"
        "beq	.L_8035AE50\n"
        "lwz	9,40(29)\n"
        "addi	4,1,8\n"
        "li	5,1\n"
        "lha	3,24(9)\n"
        "lwz	0,28(9)\n"
        "add	3,29,3\n"
        "mtlr	0\n"
        "blrl\n"
        "cmpwi	3,0\n"
        "bne	.L_8035ADF8\n"
        "cmpw	31,28\n"
        "beq	.L_8035ADF0\n"
        ".L_8035AE50:\n"
        "li	0,0\n"
        "mr	3,28\n"
        "stb	0,0(31)\n"
        ".L_8035AE5C:\n"
        "lwz	0,36(1)\n"
        "mtlr	0\n"
        "lmw	28,16(1)\n"
        "addi	1,1,32\n"
        "blr\n"
    );
}

