#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for NghResFile (stub_classes.h)
// 1 functions, 128 bytes

// 0x800D8D10 (128 bytes)
// NghResFile::FindNodeInRegistry(NghResFile::RegistryID, NghResFile::RegistryNode &)
__attribute__((noreturn))
void NghResFile::FindNodeInRegistry(int, int &) {
    __asm__ __volatile__(
        "lwz	11,16(3)\n"
        "li	8,0\n"
        "lwz	0,20(3)\n"
        "cmplw	11,0\n"
        "bge	.L_800D8D88\n"
        "lwz	0,0(11)\n"
        "cmpw	0,4\n"
        "bne	.L_800D8D4C\n"
        "lwz	0,12(11)\n"
        "li	8,1\n"
        "lwz	9,4(11)\n"
        "lwz	11,8(11)\n"
        "stw	0,12(5)\n"
        "stw	4,0(5)\n"
        "b	.L_800D8D80\n"
        ".L_800D8D4C:\n"
        "lwz	0,20(3)\n"
        "addi	11,11,16\n"
        "cmplw	11,0\n"
        "bge	.L_800D8D88\n"
        "lwz	10,0(11)\n"
        "cmpw	10,4\n"
        "bne	.L_800D8D4C\n"
        "lwz	0,12(11)\n"
        "li	8,1\n"
        "lwz	9,4(11)\n"
        "lwz	11,8(11)\n"
        "stw	0,12(5)\n"
        "stw	10,0(5)\n"
        ".L_800D8D80:\n"
        "stw	9,4(5)\n"
        "stw	11,8(5)\n"
        ".L_800D8D88:\n"
        "mr	3,8\n"
        "blr\n"
    );
}

