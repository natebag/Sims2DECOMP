#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for UIUpdateTable (stub_classes.h)
// 3 functions, 268 bytes

// 0x80181C8C (100 bytes)
// UIUpdateTable::ExecuteUpdatesPreFlash(void)
__attribute__((noreturn))
void UIUpdateTable::ExecuteUpdatesPreFlash(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	3,0(3)\n"
        "cmpwi	3,0\n"
        "beq	.L_80181CDC\n"
        ".L_80181CA8:\n"
        "lwz	0,8(3)\n"
        "lwz	31,4(3)\n"
        "cmpwi	0,50\n"
        "ble	.L_80181CD4\n"
        "lwz	9,12(3)\n"
        "cmpwi	9,0\n"
        "beq	.L_80181CD4\n"
        "lwz	0,12(9)\n"
        "mr	3,9\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80181CD4:\n"
        "mr.	3,31\n"
        "bne	.L_80181CA8\n"
        ".L_80181CDC:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80181CF0 (92 bytes)
// UIUpdateTable::ExecuteUpdatesPostFlash(void)
__attribute__((noreturn))
void UIUpdateTable::ExecuteUpdatesPostFlash(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "lwz	3,0(3)\n"
        "cmpwi	3,0\n"
        "beq	.L_80181D38\n"
        ".L_80181D0C:\n"
        "lwz	0,8(3)\n"
        "lwz	31,4(3)\n"
        "cmpwi	0,50\n"
        "bgt	.L_80181D30\n"
        "lwz	9,12(3)\n"
        "lwz	0,12(9)\n"
        "mr	3,9\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80181D30:\n"
        "mr.	3,31\n"
        "bne	.L_80181D0C\n"
        ".L_80181D38:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80181D88 (76 bytes)
// UIUpdateTable::Shutdown(void)
__attribute__((noreturn))
void UIUpdateTable::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-31488(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_80181DC4\n"
        "lwz	9,12(11)\n"
        "li	4,3\n"
        "lwz	0,12(9)\n"
        "lha	3,8(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,-31488(13)\n"
        ".L_80181DC4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

