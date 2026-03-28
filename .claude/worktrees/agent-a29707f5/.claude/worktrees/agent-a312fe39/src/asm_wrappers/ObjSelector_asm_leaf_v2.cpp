#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ObjSelector (stub_classes.h)
// 6 functions, 520 bytes

// 0x80110790 (76 bytes)
// ObjSelector::loadFile(void)
__attribute__((noreturn))
void ObjSelector::loadFile(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	11,80(30)\n"
        "mr	4,30\n"
        "lwz	9,0(11)\n"
        "lha	3,328(9)\n"
        "lwz	0,332(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	3,0(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80110840 (92 bytes)
// ObjSelector::GetMasterSelector(void)
__attribute__((noreturn))
void ObjSelector::GetMasterSelector(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	0,96(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_80110884\n"
        "lwz	3,80(31)\n"
        "mr	4,31\n"
        "lwz	9,0(3)\n"
        "lha	0,160(9)\n"
        "lwz	9,164(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "stw	3,96(31)\n"
        ".L_80110884:\n"
        "lwz	3,96(31)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80111588 (96 bytes)
// ObjSelector::CountTypeAttributes(void)
__attribute__((noreturn))
void ObjSelector::CountTypeAttributes(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,56(3)\n"
        "lwz	4,184(9)\n"
        "cmpwi	4,0\n"
        "bne	.L_801115A8\n"
        "lwz	4,28(9)\n"
        ".L_801115A8:\n"
        "lwz	3,80(3)\n"
        "lwz	9,0(3)\n"
        "lha	0,176(9)\n"
        "lwz	9,180(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "mr.	3,3\n"
        "beq	.L_801115D4\n"
        "lwz	3,4(3)\n"
        "b	.L_801115D8\n"
        ".L_801115D4:\n"
        "li	3,0\n"
        ".L_801115D8:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x801115E8 (96 bytes)
// ObjSelector::GetTypeAttributes(void)
__attribute__((noreturn))
void ObjSelector::GetTypeAttributes(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	9,56(3)\n"
        "lwz	4,184(9)\n"
        "cmpwi	4,0\n"
        "bne	.L_80111608\n"
        "lwz	4,28(9)\n"
        ".L_80111608:\n"
        "lwz	3,80(3)\n"
        "lwz	9,0(3)\n"
        "lha	0,176(9)\n"
        "lwz	9,180(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "mr.	3,3\n"
        "beq	.L_80111634\n"
        "lwz	3,8(3)\n"
        "b	.L_80111638\n"
        ".L_80111634:\n"
        "li	3,0\n"
        ".L_80111638:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x80111648 (88 bytes)
// ObjSelector::GetTreeTable(void)
__attribute__((noreturn))
void ObjSelector::GetTreeTable(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "lwz	0,60(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_80111688\n"
        "lwz	3,80(31)\n"
        "mr	4,31\n"
        "lwz	9,0(3)\n"
        "lha	0,344(9)\n"
        "lwz	9,348(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        ".L_80111688:\n"
        "lwz	3,60(31)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x801116A0 (72 bytes)
// ObjSelector::GetNormalSimDescription(void) const
__attribute__((noreturn))
void ObjSelector::GetNormalSimDescription(void) const {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,152(3)\n"
        "cmpwi	11,0\n"
        "bne	.L_801116C0\n"
        "lwz	3,140(3)\n"
        "b	.L_801116D8\n"
        ".L_801116C0:\n"
        "lwz	9,4(11)\n"
        "lha	3,344(9)\n"
        "lwz	0,348(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801116D8:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

