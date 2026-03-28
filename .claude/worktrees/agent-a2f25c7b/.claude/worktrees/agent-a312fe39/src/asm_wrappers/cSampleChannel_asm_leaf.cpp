#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for cSampleChannel (stub_classes.h)
// 5 functions, 412 bytes

// 0x80119110 (72 bytes)
// cSampleChannel::SetVolume(int)
__attribute__((noreturn))
void cSampleChannel::SetVolume(int) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,4(3)\n"
        "cmpwi	11,0\n"
        "bne	.L_80119130\n"
        "li	3,0\n"
        "b	.L_80119148\n"
        ".L_80119130:\n"
        "lwz	9,0(11)\n"
        "lha	3,96(9)\n"
        "lwz	0,100(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80119148:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x80119284 (100 bytes)
// cSampleChannel::NoteOn(void)
__attribute__((noreturn))
void cSampleChannel::NoteOn(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "li	4,0\n"
        "lwz	11,4(30)\n"
        "lwz	9,0(11)\n"
        "lwz	0,148(9)\n"
        "lha	3,144(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	11,4(30)\n"
        "lwz	9,0(11)\n"
        "lha	3,32(9)\n"
        "lwz	0,36(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x801192E8 (88 bytes)
// cSampleChannel::NoteOff(void)
__attribute__((noreturn))
void cSampleChannel::NoteOff(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	11,4(31)\n"
        "cmpwi	11,0\n"
        "beq	.L_80119328\n"
        "lwz	9,0(11)\n"
        "lwz	0,28(9)\n"
        "lha	3,24(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,4(31)\n"
        ".L_80119328:\n"
        "li	3,1\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80119340 (72 bytes)
// cSampleChannel::IsPlaying(void)
__attribute__((noreturn))
void cSampleChannel::IsPlaying(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,4(3)\n"
        "cmpwi	11,0\n"
        "bne	.L_80119360\n"
        "li	3,0\n"
        "b	.L_80119378\n"
        ".L_80119360:\n"
        "lwz	9,0(11)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80119378:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801193D8 (80 bytes)
// cSampleChannel::Unpause(void)
__attribute__((noreturn))
void cSampleChannel::Unpause(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	3,0(3)\n"
        "cmpwi	3,0\n"
        "beq	.L_80119414\n"
        "lwz	11,24(3)\n"
        "cmpwi	11,0\n"
        "beq	.L_80119414\n"
        "lwz	9,0(11)\n"
        "lha	3,64(9)\n"
        "lwz	0,68(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80119414:\n"
        "li	3,1\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

