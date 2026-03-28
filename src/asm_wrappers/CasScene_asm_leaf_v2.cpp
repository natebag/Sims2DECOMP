#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CasScene (stub_classes.h)
// 1 functions, 68 bytes

// 0x80165990 (68 bytes)
// CasScene::DrawRoom(ERC *, CasScene::RoomId, EMat4 &)
__attribute__((noreturn))
void CasScene::DrawRoom(ERC *, int, EMat4 &) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "cmpwi	5,0\n"
        "bne	.L_801659C4\n"
        "lwz	9,4(11)\n"
        "mr	5,6\n"
        "lha	3,120(9)\n"
        "lwz	0,124(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_801659C4:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

