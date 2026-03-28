#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for EWindow (stub_classes.h)
// 1 functions, 172 bytes

// 0x802FFF94 (172 bytes)
// EWindow::ScaleScissorRectForScreenshot(TRect<float> *, TRect<float> *)
__attribute__((noreturn))
void EWindow::ScaleScissorRectForScreenshot(TRect<float> *, TRect<float> *) {
    __asm__ __volatile__(
        "lis	11,-32693\n"
        "lfs	7,0(3)\n"
        "lfs	0,2292(11)\n"
        "addi	10,11,2292\n"
        "lfs	8,4(3)\n"
        "lis	8,-32693\n"
        "fmuls	7,7,0\n"
        "lfs	10,8(3)\n"
        "stfs	7,0(3)\n"
        "lis	9,-32702\n"
        "lfs	11,12(3)\n"
        "addi	7,8,2304\n"
        "lfs	0,4(10)\n"
        "lfs	5,-2204(9)\n"
        "fmuls	8,8,0\n"
        "stfs	8,4(3)\n"
        "lfs	0,2292(11)\n"
        "fmuls	10,10,0\n"
        "stfs	10,8(3)\n"
        "lfs	0,4(10)\n"
        "fmuls	11,11,0\n"
        "stfs	11,12(3)\n"
        "lfs	12,0(4)\n"
        "lfs	0,8(4)\n"
        "lfs	6,4(4)\n"
        "lfs	13,12(4)\n"
        "fsubs	0,0,12\n"
        "lfs	9,2304(8)\n"
        "fadds	0,0,5\n"
        "lfs	12,4(7)\n"
        "fsubs	13,13,6\n"
        "fadds	13,13,5\n"
        "fmuls	0,0,9\n"
        "fmuls	13,13,12\n"
        "fsubs	10,10,0\n"
        "fsubs	11,11,13\n"
        "stfs	10,8(3)\n"
        "fsubs	7,7,0\n"
        "stfs	11,12(3)\n"
        "fsubs	8,8,13\n"
        "stfs	7,0(3)\n"
        "stfs	8,4(3)\n"
        "blr\n"
    );
}

