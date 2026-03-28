#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ENgcTexture (stub_classes.h)
// 3 functions, 204 bytes

// 0x8034FB10 (68 bytes)
// ENgcTexture::ClearTileFlags(void)
__attribute__((noreturn))
void ENgcTexture::ClearTileFlags(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,8(3)\n"
        "lwz	11,40(3)\n"
        "clrrwi	0,0,2\n"
        "stw	0,8(3)\n"
        "lwz	9,36(11)\n"
        "lha	3,88(9)\n"
        "lwz	0,92(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x8034FB54 (68 bytes)
// ENgcTexture::ClearSwizzleFlag(void)
__attribute__((noreturn))
void ENgcTexture::ClearSwizzleFlag(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,8(3)\n"
        "lwz	11,40(3)\n"
        "rlwinm	0,0,0,25,23\n"
        "stw	0,8(3)\n"
        "lwz	9,36(11)\n"
        "lha	3,96(9)\n"
        "lwz	0,100(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

// 0x8034FB98 (68 bytes)
// ENgcTexture::SetSwizzleFlag(void)
__attribute__((noreturn))
void ENgcTexture::SetSwizzleFlag(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "lwz	0,8(3)\n"
        "lwz	11,40(3)\n"
        "ori	0,0,128\n"
        "stw	0,8(3)\n"
        "lwz	9,36(11)\n"
        "lha	3,104(9)\n"
        "lwz	0,108(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
}

