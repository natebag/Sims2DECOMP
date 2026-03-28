#include "types.h"
#include "stub_classes.h"
// Inline asm leaf matches for CDirtyXmlNode (stub_classes.h)
// 1 functions, 80 bytes

// 0x8023A8FC (80 bytes)
// CDirtyXmlNode::getFirstAttribute(void)
__attribute__((noreturn))
void CDirtyXmlNode::getFirstAttribute(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "li	0,0\n"
        "lwz	9,0(4)\n"
        "stw	0,24(4)\n"
        "mr	30,3\n"
        "lha	0,32(9)\n"
        "lwz	9,36(9)\n"
        "add	4,4,0\n"
        "mtlr	9\n"
        "crclr	4*cr1+eq\n"
        "blrl\n"
        "mr	3,30\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
}

