#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EResPrefetchFile (stub_classes.h)
// 1 functions, 108 bytes

// 0x803131D0 (108 bytes)
// EResPrefetchFile::Seek(int, EFile::SeekType)
__attribute__((noreturn))
void EResPrefetchFile::Seek(int, int) {
    __asm__ __volatile__(
        "cmpwi	5,0\n"
        "bne	.L_803131EC\n"
        "lwz	0,64(3)\n"
        "mr	3,4\n"
        "cmpw	4,0\n"
        "beqlr\n"
        "blr\n"
        ".L_803131EC:\n"
        "lwz	10,48(3)\n"
        "lwz	9,52(3)\n"
        "lwz	0,56(3)\n"
        "add	11,10,4\n"
        "add	9,9,0\n"
        "cmplw	11,9\n"
        "blt	.L_80313224\n"
        "cmpw	9,10\n"
        "bne	.L_80313218\n"
        "lwz	0,64(3)\n"
        "b	.L_8031322C\n"
        ".L_80313218:\n"
        "lwz	0,64(3)\n"
        "stw	9,48(3)\n"
        "b	.L_8031322C\n"
        ".L_80313224:\n"
        "lwz	0,64(3)\n"
        "stw	11,48(3)\n"
        ".L_8031322C:\n"
        "add	0,0,4\n"
        "stw	0,64(3)\n"
        "lwz	3,64(3)\n"
        "blr\n"
    );
}

