#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ObjFnTableQuickData (stub_classes.h)
// 3 functions, 272 bytes

// 0x801101F4 (68 bytes)
// ObjFnTableQuickData::LoadFromDataID(ObjectDataID &)
__attribute__((noreturn))
void ObjFnTableQuickData::LoadFromDataID(ObjectDataID &) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,0(3)\n"
        "lha	5,4(4)\n"
        "lha	0,144(9)\n"
        "lwz	9,148(9)\n"
        "add	3,3,0\n"
        "lwz	4,0(4)\n"
        "mtlr	9\n"
        "blrl\n"
        "subfic	0,3,0\n"
        "adde	3,0,3\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x80110250 (112 bytes)
// ObjFnTableQuickData::QueryInterface(unsigned int, void **)
__attribute__((noreturn))
void ObjFnTableQuickData::QueryInterface(unsigned int, void **) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,5\n"
        "beq	.L_801102A8\n"
        "cmpwi	4,1\n"
        "beq	.L_80110284\n"
        "lis	0,19427\n"
        "ori	0,0,18658\n"
        "cmpw	4,0\n"
        "bne	.L_801102A8\n"
        ".L_80110284:\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "stw	31,0(30)\n"
        "li	3,1\n"
        "b	.L_801102AC\n"
        ".L_801102A8:\n"
        "li	3,0\n"
        ".L_801102AC:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x801102D4 (92 bytes)
// ObjFnTableQuickData::Release(void)
__attribute__((noreturn))
void ObjFnTableQuickData::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,20(11)\n"
        "addi	3,9,-1\n"
        "stw	3,20(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_80110320\n"
        "cmpwi	11,0\n"
        "beq	.L_8011031C\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,96(9)\n"
        "lwz	0,100(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8011031C:\n"
        "li	3,0\n"
        ".L_80110320:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

