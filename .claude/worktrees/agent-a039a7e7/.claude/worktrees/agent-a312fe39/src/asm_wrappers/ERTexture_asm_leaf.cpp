#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ERTexture (stub_classes.h)
// 3 functions, 396 bytes

// 0x80320C00 (80 bytes)
// ERTexture::Deallocate(void)
__attribute__((noreturn))
void ERTexture::Deallocate(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lwz	11,-26392(13)\n"
        "mr	30,3\n"
        "lwz	4,20(30)\n"
        "lwz	9,0(11)\n"
        "lwz	0,196(9)\n"
        "lha	3,192(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "li	0,0\n"
        "stw	0,20(30)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x80320C50 (176 bytes)
// ERTexture::Refresh(EFile *)
__attribute__((noreturn))
void ERTexture::Refresh(EFile *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	30,4\n"
        "beq	.L_80320CEC\n"
        "lwz	0,20(31)\n"
        "cmpwi	0,0\n"
        "bne	.L_80320C98\n"
        "lwz	9,0(31)\n"
        "mr	4,30\n"
        "lha	3,72(9)\n"
        "lwz	0,76(9)\n"
        "add	3,31,3\n"
        "mtlr	0\n"
        "blrl\n"
        "b	.L_80320CEC\n"
        ".L_80320C98:\n"
        "lwz	11,-26392(13)\n"
        "lwz	9,0(11)\n"
        "lwz	0,68(9)\n"
        "lha	3,64(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	9,0(31)\n"
        "mr	4,30\n"
        "lwz	0,76(9)\n"
        "lha	3,72(9)\n"
        "mtlr	0\n"
        "add	3,31,3\n"
        "blrl\n"
        "lwz	11,-26392(13)\n"
        "lwz	9,0(11)\n"
        "lha	3,64(9)\n"
        "lwz	0,68(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_80320CEC:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

// 0x803210F4 (140 bytes)
// ERTexture::IsSafeToDelete(void)
__attribute__((noreturn))
void ERTexture::IsSafeToDelete(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        "lwz	0,20(30)\n"
        "cmpwi	0,0\n"
        "beq	.L_80321168\n"
        "lwz	0,-26312(13)\n"
        "cmpwi	0,0\n"
        "bne	.L_8032112C\n"
        "b	.L_80321168\n"
        ".L_80321124:\n"
        "li	3,0\n"
        "b	.L_8032116C\n"
        ".L_8032112C:\n"
        "li	31,0\n"
        ".L_80321130:\n"
        "lwz	11,-26312(13)\n"
        "mr	4,31\n"
        "lwz	9,824(11)\n"
        "lwz	0,28(9)\n"
        "lha	3,24(9)\n"
        "mtlr	0\n"
        "add	3,11,3\n"
        "blrl\n"
        "lwz	0,20(30)\n"
        "cmpw	3,0\n"
        "beq	.L_80321124\n"
        "addi	31,31,1\n"
        "cmpwi	31,1\n"
        "ble	.L_80321130\n"
        ".L_80321168:\n"
        "li	3,1\n"
        ".L_8032116C:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

