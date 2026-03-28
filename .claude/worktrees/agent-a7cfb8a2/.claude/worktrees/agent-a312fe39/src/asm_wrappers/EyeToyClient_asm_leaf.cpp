#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EyeToyClient (stub_classes.h)
// 2 functions, 304 bytes

// 0x800379D0 (140 bytes)
// EyeToyClient::AcquireTexture(int, int, int)
__attribute__((noreturn))
void EyeToyClient::AcquireTexture(int, int, int) {
    __asm__ __volatile__(
        "stwu	1,-40(1)\n"
        "mflr	0\n"
        "stw	0,44(1)\n"
        "li	0,0\n"
        "addi	9,1,8\n"
        "stw	0,8(1)\n"
        "li	10,32\n"
        "stb	10,26(9)\n"
        "li	8,64\n"
        "stb	0,25(9)\n"
        "li	11,1\n"
        "stb	0,27(9)\n"
        "stb	11,24(9)\n"
        "sth	8,16(9)\n"
        "stw	0,28(9)\n"
        "stw	0,4(9)\n"
        "stw	0,8(9)\n"
        "sth	8,18(9)\n"
        "sth	0,20(9)\n"
        "sth	0,22(9)\n"
        "sth	3,24(1)\n"
        "sth	4,26(1)\n"
        "stb	5,34(1)\n"
        "mr	4,9\n"
        "lwz	11,-26392(13)\n"
        "lwz	9,0(11)\n"
        "lha	3,184(9)\n"
        "lwz	0,188(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,44(1)\n"
        "mtlr	0\n"
        "addi	1,1,40\n"
        "blr\n"
    );
}

// 0x80037A9C (164 bytes)
// EyeToyClient::AcquireRenderSurface(int, int, int)
__attribute__((noreturn))
void EyeToyClient::AcquireRenderSurface(int, int, int) {
    __asm__ __volatile__(
        "stwu	1,-56(1)\n"
        "mflr	0\n"
        "stw	0,60(1)\n"
        "addi	10,1,8\n"
        "li	0,64\n"
        "stw	0,4(10)\n"
        "lis	9,-32707\n"
        "stw	0,8(1)\n"
        "li	11,1\n"
        "lfs	0,5708(9)\n"
        "li	0,3\n"
        "stw	0,8(10)\n"
        "addi	8,1,20\n"
        "stw	11,28(10)\n"
        "li	7,0\n"
        "stw	11,24(10)\n"
        "stfs	0,40(1)\n"
        "stfs	0,48(1)\n"
        "stfs	0,44(1)\n"
        "lwz	9,40(1)\n"
        "lwz	11,44(1)\n"
        "lwz	0,48(1)\n"
        "stw	9,20(1)\n"
        "stw	11,4(8)\n"
        "stw	0,8(8)\n"
        "stw	3,8(1)\n"
        "stw	4,12(1)\n"
        "stw	7,16(1)\n"
        "mr	4,10\n"
        "stw	7,32(1)\n"
        "lwz	11,-26392(13)\n"
        "lwz	9,0(11)\n"
        "lha	3,208(9)\n"
        "lwz	0,212(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        "lwz	0,60(1)\n"
        "mtlr	0\n"
        "addi	1,1,56\n"
        "blr\n"
    );
}

