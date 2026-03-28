#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for XObjLang (stub_classes.h)
// 1 functions, 116 bytes

// 0x801523AC (116 bytes)
// XObjLang::GetConstantsID(short, short *, int *)
__attribute__((noreturn))
void XObjLang::GetConstantsID(short, short *, int *) {
    __asm__ __volatile__(
        "rlwinm	0,3,19,29,31\n"
        "cmpwi	0,1\n"
        "beq	.L_801523E0\n"
        "bgt	.L_801523C8\n"
        "cmpwi	0,0\n"
        "beq	.L_801523D4\n"
        "b	.L_801523F8\n"
        ".L_801523C8:\n"
        "cmpwi	0,2\n"
        "beq	.L_801523EC\n"
        "b	.L_801523F8\n"
        ".L_801523D4:\n"
        "li	0,4096\n"
        "sth	0,0(4)\n"
        "b	.L_80152400\n"
        ".L_801523E0:\n"
        "li	0,8192\n"
        "sth	0,0(4)\n"
        "b	.L_80152400\n"
        ".L_801523EC:\n"
        "li	0,256\n"
        "sth	0,0(4)\n"
        "b	.L_80152400\n"
        ".L_801523F8:\n"
        "li	3,0\n"
        "blr\n"
        ".L_80152400:\n"
        "lhz	0,0(4)\n"
        "rlwinm	9,3,25,26,31\n"
        "clrlwi	11,3,25\n"
        "add	0,0,9\n"
        "li	3,1\n"
        "sth	0,0(4)\n"
        "stw	11,0(5)\n"
        "blr\n"
    );
}

