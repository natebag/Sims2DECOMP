#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ESimsDataManager (stub_classes.h)
// 2 functions, 236 bytes

// 0x800231C0 (112 bytes)
// ESimsDataManager::incWorkQueued(void)
__attribute__((noreturn))
void ESimsDataManager::incWorkQueued(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stmw	30,16(1)\n"
        "stw	0,28(1)\n"
        "mr	30,3\n"
        "li	4,-1\n"
        "stw	30,8(1)\n"
        "lwz	9,0(30)\n"
        "lwz	0,20(9)\n"
        "lha	3,16(9)\n"
        "mtlr	0\n"
        "add	3,30,3\n"
        "blrl\n"
        "lwz	9,3372(30)\n"
        "lwz	10,8(1)\n"
        "addi	9,9,1\n"
        "stw	9,3372(30)\n"
        "lwz	11,0(10)\n"
        "lha	3,24(11)\n"
        "lwz	0,28(11)\n"
        "add	3,10,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lmw	30,16(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

// 0x80023230 (124 bytes)
// ESimsDataManager::decWorkQueued(void)
__attribute__((noreturn))
void ESimsDataManager::decWorkQueued(void) {
    __asm__ __volatile__(
        "stwu	1,-24(1)\n"
        "mflr	0\n"
        "stw	31,20(1)\n"
        "stw	0,28(1)\n"
        "mr	31,3\n"
        "li	4,-1\n"
        "stw	31,8(1)\n"
        "lwz	9,0(31)\n"
        "lha	3,16(9)\n"
        "lwz	0,20(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	9,3372(31)\n"
        "addi	9,9,-1\n"
        "stw	9,3372(31)\n"
        "cmpwi	9,0\n"
        "bne	.L_8002327C\n"
        "stw	9,3360(31)\n"
        ".L_8002327C:\n"
        "lwz	3,8(1)\n"
        "lwz	9,0(3)\n"
        "lha	0,24(9)\n"
        "lwz	9,28(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "lwz	0,28(1)\n"
        "mtlr	0\n"
        "lwz	31,20(1)\n"
        "addi	1,1,24\n"
        "blr\n"
    );
}

