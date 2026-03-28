#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CasScenePersonal (stub_classes.h)
// 1 functions, 100 bytes

// 0x801758A8 (100 bytes)
// CasScenePersonal::GetMirrorCorners(CasScene::RoomId, EVec3 *) const
__attribute__((noreturn))
void CasScenePersonal::GetMirrorCorners(int, EVec3 *) const {
    __asm__ __volatile__(
        "cmpwi	4,0\n"
        "bne	.L_80175904\n"
        "lis	9,-32696\n"
        "li	11,48\n"
        "addi	9,9,31204\n"
        ".L_801758BC:\n"
        "lwz	0,0(9)\n"
        "addic.	11,11,-24\n"
        "stw	0,0(5)\n"
        "lwz	0,4(9)\n"
        "stw	0,4(5)\n"
        "lwz	0,8(9)\n"
        "stw	0,8(5)\n"
        "lwz	0,12(9)\n"
        "stw	0,12(5)\n"
        "lwz	0,16(9)\n"
        "stw	0,16(5)\n"
        "lwz	0,20(9)\n"
        "addi	9,9,24\n"
        "stw	0,20(5)\n"
        "addi	5,5,24\n"
        "bne	.L_801758BC\n"
        "li	3,1\n"
        "blr\n"
        ".L_80175904:\n"
        "li	3,0\n"
        "blr\n"
    );
}

