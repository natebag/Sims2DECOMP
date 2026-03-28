#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EThread (stub_classes.h)
// 1 functions, 108 bytes

// 0x802D8610 (108 bytes)
// EThread::IsValidMemoryBlock(void *, int)
__attribute__((noreturn))
void EThread::IsValidMemoryBlock(void *, int) {
    __asm__ __volatile__(
        "mr.	10,3\n"
        "beq	.L_802D8674\n"
        "lwz	9,-22764(13)\n"
        "cmpwi	9,0\n"
        "beq	.L_802D866C\n"
        "add	11,10,4\n"
        ".L_802D8628:\n"
        "lwz	3,796(9)\n"
        "cmplw	11,3\n"
        "ble	.L_802D8660\n"
        "lwz	0,800(9)\n"
        "add	4,3,0\n"
        "cmplw	10,4\n"
        "bge	.L_802D8660\n"
        "cmplw	10,3\n"
        "blt	.L_802D8658\n"
        "cmplw	11,4\n"
        "li	3,1\n"
        "blelr\n"
        ".L_802D8658:\n"
        "li	3,0\n"
        "blr\n"
        ".L_802D8660:\n"
        "lwz	9,820(9)\n"
        "cmpwi	9,0\n"
        "bne	.L_802D8628\n"
        ".L_802D866C:\n"
        "li	3,1\n"
        "blr\n"
        ".L_802D8674:\n"
        "li	3,1\n"
        "blr\n"
    );
}

