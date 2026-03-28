#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for PaneItem (stub_classes.h)
// 3 functions, 204 bytes

// 0x803A0828 (68 bytes)
// PaneItem::GetSize(void)
__attribute__((noreturn))
void PaneItem::GetSize(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	9,28(30)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "addi	3,30,20\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x803A0880 (68 bytes)
// PaneItem::GetSizeX(void)
__attribute__((noreturn))
void PaneItem::GetSizeX(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	9,28(30)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lfs	1,20(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x803A08D8 (68 bytes)
// PaneItem::GetSizeY(void)
__attribute__((noreturn))
void PaneItem::GetSizeY(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	9,28(30)\n"
        "lha	3,40(9)\n"
        "lwz	0,44(9)\n"
        "add	3,30,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lfs	1,24(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

