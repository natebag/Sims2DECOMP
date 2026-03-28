#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for UIDrawTable (stub_classes.h)
// 3 functions, 276 bytes

// 0x8017AA50 (100 bytes)
// UIDrawTable::ExecuteDrawsPreFlash(ERC *)
__attribute__((noreturn))
void UIDrawTable::ExecuteDrawsPreFlash(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	3,0(3)\n"
        "mr	30,4\n"
        "cmpwi	3,0\n"
        "beq	.L_8017AAA0\n"
        ".L_8017AA70:\n"
        "lwz	0,8(3)\n"
        "lwz	31,4(3)\n"
        "cmpwi	0,50\n"
        "ble	.L_8017AA98\n"
        "lwz	9,12(3)\n"
        "mr	4,30\n"
        "lwz	0,12(9)\n"
        "mr	3,9\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8017AA98:\n"
        "mr.	3,31\n"
        "bne	.L_8017AA70\n"
        ".L_8017AAA0:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8017AAB4 (100 bytes)
// UIDrawTable::ExecuteDrawsPostFlash(ERC *)
__attribute__((noreturn))
void UIDrawTable::ExecuteDrawsPostFlash(ERC *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	3,0(3)\n"
        "mr	30,4\n"
        "cmpwi	3,0\n"
        "beq	.L_8017AB04\n"
        ".L_8017AAD4:\n"
        "lwz	0,8(3)\n"
        "lwz	31,4(3)\n"
        "cmpwi	0,50\n"
        "bgt	.L_8017AAFC\n"
        "lwz	9,12(3)\n"
        "mr	4,30\n"
        "lwz	0,12(9)\n"
        "mr	3,9\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8017AAFC:\n"
        "mr.	3,31\n"
        "bne	.L_8017AAD4\n"
        ".L_8017AB04:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x8017AB54 (76 bytes)
// UIDrawTable::Shutdown(void)
__attribute__((noreturn))
void UIDrawTable::Shutdown(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	11,-31516(13)\n"
        "cmpwi	11,0\n"
        "beq	.L_8017AB90\n"
        "lwz	9,12(11)\n"
        "li	4,3\n"
        "lwz	0,12(9)\n"
        "lha	3,8(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,-31516(13)\n"
        ".L_8017AB90:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

