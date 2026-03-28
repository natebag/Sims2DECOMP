#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ImageProcessingManager (stub_classes.h)
// 1 functions, 108 bytes

// 0x8032949C (108 bytes)
// ImageProcessingManager::SetStageFilter(int, ImageProcessingManager::FilterDescriptor *)
__attribute__((noreturn))
void ImageProcessingManager::SetStageFilter(int, int *) {
    __asm__ __volatile__(
        "mulli	3,3,36\n"
        "lwz	0,-26588(13)\n"
        "li	9,24\n"
        "add	3,3,0\n"
        ".L_803294AC:\n"
        "lwz	0,0(4)\n"
        "addic.	9,9,-24\n"
        "stw	0,0(3)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(3)\n"
        "lwz	0,8(4)\n"
        "stw	0,8(3)\n"
        "lwz	0,12(4)\n"
        "stw	0,12(3)\n"
        "lwz	0,16(4)\n"
        "stw	0,16(3)\n"
        "lwz	0,20(4)\n"
        "addi	4,4,24\n"
        "stw	0,20(3)\n"
        "addi	3,3,24\n"
        "bne	.L_803294AC\n"
        "lwz	0,0(4)\n"
        "stw	0,0(3)\n"
        "lwz	0,4(4)\n"
        "stw	0,4(3)\n"
        "lwz	0,8(4)\n"
        "stw	0,8(3)\n"
        "blr\n"
    );
}

