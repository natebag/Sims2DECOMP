#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ObjectIterator (stub_classes.h)
// 1 functions, 116 bytes

// 0x800F29F8 (116 bytes)
// ObjectIterator::init(CTilePt &, ObjectIterator::IterateType)
__attribute__((noreturn))
void ObjectIterator::init(CTilePt &, int) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	29,12(1)\n"
        "stw	0,28(1)\n"
        "lwz	11,-21484(13)\n"
        "mr	30,3\n"
        "mr	29,5\n"
        "lwz	9,0(11)\n"
        "lwz	0,596(9)\n"
        "lha	3,592(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	11,-21484(13)\n"
        "mr	4,3\n"
        "lwz	9,0(11)\n"
        "lha	3,144(9)\n"
        "lwz	0,148(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	29,8(30)\n"
        "stw	3,4(30)\n"
        "stw	3,0(30)\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	29,12(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

