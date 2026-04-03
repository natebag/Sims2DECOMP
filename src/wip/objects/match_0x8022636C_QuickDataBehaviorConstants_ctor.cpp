// 0x8022636C (68 bytes)
// QuickDataBehaviorConstants::QuickDataBehaviorConstants(void)

__attribute__((noreturn))
QuickDataBehaviorConstants::QuickDataBehaviorConstants(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "mr	30,3\n"
        ".long 0x4bfff2e1\n"
        "lis	9,-32698\n"
        "li	0,0\n"
        "addi	9,9,22224\n"
        "stw	0,28(30)\n"
        "stw	9,0(30)\n"
        "mr	3,30\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
    __builtin_unreachable();
}
