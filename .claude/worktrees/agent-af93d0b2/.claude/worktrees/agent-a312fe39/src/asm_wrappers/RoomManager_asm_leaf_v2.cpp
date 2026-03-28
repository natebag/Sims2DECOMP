#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for RoomManager (stub_classes.h)
// 1 functions, 128 bytes

// 0x80136FB4 (128 bytes)
// RoomManager::GetOutsideAmbientLevel(void)
__attribute__((noreturn))
void RoomManager::GetOutsideAmbientLevel(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	3,-21496(13)\n"
        "lwz	9,0(3)\n"
        "lha	0,240(9)\n"
        "lwz	9,244(9)\n"
        "add	3,3,0\n"
        "mtlr	9\n"
        "blrl\n"
        "cmpwi	3,1\n"
        "beq	.L_80137010\n"
        "ble	.L_80137004\n"
        "cmpwi	3,2\n"
        "bne	.L_80136FFC\n"
        "lis	9,-32706\n"
        "lfs	0,-11436(9)\n"
        "b	.L_80137018\n"
        ".L_80136FFC:\n"
        "cmpwi	3,3\n"
        "beq	.L_80137010\n"
        ".L_80137004:\n"
        "lis	9,-32706\n"
        "lfs	0,-11432(9)\n"
        "b	.L_80137018\n"
        ".L_80137010:\n"
        "lis	9,-32706\n"
        "lfs	0,-11428(9)\n"
        ".L_80137018:\n"
        "lwz	9,-21356(13)\n"
        "lfs	1,12(9)\n"
        "fmuls	1,1,0\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

