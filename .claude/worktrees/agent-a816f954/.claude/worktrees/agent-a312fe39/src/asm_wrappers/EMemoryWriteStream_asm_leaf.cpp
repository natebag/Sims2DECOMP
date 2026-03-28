#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EMemoryWriteStream (stub_classes.h)
// 1 functions, 152 bytes

// 0x802E0DF8 (152 bytes)
// EMemoryWriteStream::WriteToStream(EStream &, int, int)
__attribute__((noreturn))
void EMemoryWriteStream::WriteToStream(EStream &, int, int) {
    __asm__ __volatile__(
        "stwu	1,-32(1)\n"
        "mflr	0\n"
        "stmw	27,12(1)\n"
        "stw	0,36(1)\n"
        "mr	27,3\n"
        "mr	28,4\n"
        "mr	30,5\n"
        "mr.	29,6\n"
        "beq	.L_802E0E7C\n"
        ".L_802E0E1C:\n"
        "mr	9,30\n"
        "cmpwi	30,0\n"
        "bge	.L_802E0E2C\n"
        "addi	9,30,4095\n"
        ".L_802E0E2C:\n"
        "srawi	9,9,12\n"
        "lwz	11,32(27)\n"
        "slwi	9,9,2\n"
        "clrlwi	0,30,20\n"
        "lwzx	10,11,9\n"
        "subfic	31,0,4096\n"
        "cmpw	29,31\n"
        "add	4,10,0\n"
        "bge	.L_802E0E54\n"
        "mr	31,29\n"
        ".L_802E0E54:\n"
        "lwz	9,24(28)\n"
        "mr	5,31\n"
        "add	30,30,31\n"
        "lha	3,56(9)\n"
        "lwz	0,60(9)\n"
        "add	3,28,3\n"
        "mtlr	0\n"
        "blrl\n"
        "subf.	29,31,29\n"
        "bne	.L_802E0E1C\n"
        ".L_802E0E7C:\n"
        "lwz	0,36(1)\n"
        "mtlr	0\n"
        "lmw	27,12(1)\n"
        "addi	1,1,32\n"
        "blr\n"
    );
}

