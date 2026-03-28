#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ERedBlackTree (stub_classes.h)
// 1 functions, 124 bytes

// 0x802CDAA0 (124 bytes)
// ERedBlackTree::RotateRight(ERedBlackTreeNode *)
__attribute__((noreturn))
void ERedBlackTree::RotateRight(ERedBlackTreeNode *) {
    __asm__ __volatile__(
        "lwz	11,0(4)\n"
        "lis	9,-32700\n"
        "addi	9,9,-4812\n"
        "lwz	0,4(11)\n"
        "stw	0,0(4)\n"
        "lwz	10,4(11)\n"
        "cmpw	10,9\n"
        "beq	.L_802CDAC4\n"
        "stw	4,8(10)\n"
        ".L_802CDAC4:\n"
        "cmpw	11,9\n"
        "beq	.L_802CDAD4\n"
        "lwz	0,8(4)\n"
        "stw	0,8(11)\n"
        ".L_802CDAD4:\n"
        "lwz	9,8(4)\n"
        "cmpwi	9,0\n"
        "beq	.L_802CDAFC\n"
        "lwz	0,4(9)\n"
        "cmpw	4,0\n"
        "bne	.L_802CDAF4\n"
        "stw	11,4(9)\n"
        "b	.L_802CDB00\n"
        ".L_802CDAF4:\n"
        "stw	11,0(9)\n"
        "b	.L_802CDB00\n"
        ".L_802CDAFC:\n"
        "stw	11,8(3)\n"
        ".L_802CDB00:\n"
        "lis	9,-32700\n"
        "stw	4,4(11)\n"
        "addi	9,9,-4812\n"
        "cmpw	4,9\n"
        "beqlr\n"
        "stw	11,8(4)\n"
        "blr\n"
    );
}

