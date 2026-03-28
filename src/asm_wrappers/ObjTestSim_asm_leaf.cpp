#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for ObjTestSim (stub_classes.h)
// 1 functions, 80 bytes

// 0x80112138 (80 bytes)
// ObjTestSim::SetStackObject(cXObject *)
__attribute__((noreturn))
void ObjTestSim::SetStackObject(cXObject *) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stw	31,12(1)\n"
        "stw	0,20(1)\n"
        "mr	31,3\n"
        "mr.	4,4\n"
        "beq	.L_80112170\n"
        "lwz	9,4(4)\n"
        "lha	3,528(9)\n"
        "lwz	0,532(9)\n"
        "add	3,4,3\n"
        "mtlr	0\n"
        "blrl\n"
        "mr	4,3\n"
        ".L_80112170:\n"
        "stw	4,4(31)\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lwz	31,12(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

