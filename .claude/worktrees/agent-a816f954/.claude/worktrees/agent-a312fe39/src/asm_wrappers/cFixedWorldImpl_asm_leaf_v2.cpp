#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cFixedWorldImpl (stub_classes.h)
// 1 functions, 128 bytes

// 0x80151C98 (128 bytes)
// cFixedWorldImpl::IsGrassAt(CTilePt &)
__attribute__((noreturn))
void cFixedWorldImpl::IsGrassAt(CTilePt &) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,0(3)\n"
        "lha	0,136(9)\n"
        "lwz	9,140(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lis	9,-32697\n"
        "li	0,0\n"
        "lwz	11,24224(9)\n"
        "lwz	11,0(11)\n"
        "cmpwi	11,0\n"
        "beq	.L_80151CD8\n"
        "lwz	0,-4(11)\n"
        ".L_80151CD8:\n"
        "cmpw	3,0\n"
        "bge	.L_80151D04\n"
        "slwi	9,3,2\n"
        "lwzx	11,11,9\n"
        "lwz	3,16(11)\n"
        "cmpwi	3,8\n"
        "beq	.L_80151CFC\n"
        "cmpwi	3,9\n"
        "bne	.L_80151D04\n"
        ".L_80151CFC:\n"
        "li	3,1\n"
        "b	.L_80151D08\n"
        ".L_80151D04:\n"
        "li	3,0\n"
        ".L_80151D08:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

