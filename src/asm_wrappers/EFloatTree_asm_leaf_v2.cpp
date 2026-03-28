#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EFloatTree (stub_classes.h)
// 3 functions, 276 bytes

// 0x8035B534 (124 bytes)
// EFloatTree::RotateRight(EFloatTreeNode *)
__attribute__((noreturn))
void EFloatTree::RotateRight(EFloatTreeNode *) {
    __asm__ __volatile__(
        "lwz	11,0(4)\n"
        "lis	9,-32700\n"
        "addi	9,9,11784\n"
        "lwz	0,4(11)\n"
        "stw	0,0(4)\n"
        "lwz	10,4(11)\n"
        "cmpw	10,9\n"
        "beq	.L_8035B558\n"
        "stw	4,8(10)\n"
        ".L_8035B558:\n"
        "cmpw	11,9\n"
        "beq	.L_8035B568\n"
        "lwz	0,8(4)\n"
        "stw	0,8(11)\n"
        ".L_8035B568:\n"
        "lwz	9,8(4)\n"
        "cmpwi	9,0\n"
        "beq	.L_8035B590\n"
        "lwz	0,4(9)\n"
        "cmpw	4,0\n"
        "bne	.L_8035B588\n"
        "stw	11,4(9)\n"
        "b	.L_8035B594\n"
        ".L_8035B588:\n"
        "stw	11,0(9)\n"
        "b	.L_8035B594\n"
        ".L_8035B590:\n"
        "stw	11,8(3)\n"
        ".L_8035B594:\n"
        "lis	9,-32700\n"
        "stw	4,4(11)\n"
        "addi	9,9,11784\n"
        "cmpw	4,9\n"
        "beqlr\n"
        "stw	11,8(4)\n"
        "blr\n"
    );
}

// 0x8035B788 (68 bytes)
// EFloatTree::FindKeyOrParent(float) const
__attribute__((noreturn))
void EFloatTree::FindKeyOrParent(float) const {
    __asm__ __volatile__(
        "lwz	3,8(3)\n"
        "lis	9,-32700\n"
        "addi	9,9,11784\n"
        "li	11,0\n"
        ".L_8035B798:\n"
        "cmpw	3,9\n"
        "beq	.L_8035B7C4\n"
        "lfs	0,28(3)\n"
        "fcmpu	cr0,1,0\n"
        "beqlr\n"
        "mr	11,3\n"
        "bge	.L_8035B7BC\n"
        "lwz	3,0(11)\n"
        "b	.L_8035B798\n"
        ".L_8035B7BC:\n"
        "lwz	3,4(11)\n"
        "b	.L_8035B798\n"
        ".L_8035B7C4:\n"
        "mr	3,11\n"
        "blr\n"
    );
}

// 0x8035BE5C (84 bytes)
// EFloatTree::Find(float, unsigned int *) const
__attribute__((noreturn))
void EFloatTree::Find(float, unsigned int *) const {
    __asm__ __volatile__(
        "lwz	3,8(3)\n"
        "lis	9,-32700\n"
        "addi	9,9,11784\n"
        "cmpw	3,9\n"
        "beq	.L_8035BEA8\n"
        "cmpwi	cr7,4,0\n"
        ".L_8035BE74:\n"
        "lfs	0,28(3)\n"
        "fcmpu	cr0,1,0\n"
        "bne	.L_8035BE90\n"
        "beqlr	cr7\n"
        "lwz	0,24(3)\n"
        "stw	0,0(4)\n"
        "blr\n"
        ".L_8035BE90:\n"
        "bge	.L_8035BE9C\n"
        "lwz	3,0(3)\n"
        "b	.L_8035BEA0\n"
        ".L_8035BE9C:\n"
        "lwz	3,4(3)\n"
        ".L_8035BEA0:\n"
        "cmpw	3,9\n"
        "bne	.L_8035BE74\n"
        ".L_8035BEA8:\n"
        "li	3,0\n"
        "blr\n"
    );
}

