// 0x802263B0 (80 bytes)
// QuickDataBehaviorConstants::~QuickDataBehaviorConstants(void)

__attribute__((noreturn))
QuickDataBehaviorConstants::~QuickDataBehaviorConstants(void) {
    __asm__ __volatile__(
        "stwu	1,-16(1)\n"
        "mflr	0\n"
        "stmw	30,8(1)\n"
        "stw	0,20(1)\n"
        "lis	9,-32698\n"
        "mr	31,3\n"
        "mr	30,4\n"
        "addi	9,9,22224\n"
        "stw	9,0(31)\n"
        "li	4,0\n"
        ".long 0x4bfff3b9\n"
        "andi.	0,30,1\n"
        "beq	.L_8015A7B8\n"
        "mr	3,31\n"
        ".long 0x4bfff69d\n"
        ".L_8015A7B8:\n"
        "lwz	0,20(1)\n"
        "mtlr	0\n"
        "lmw	30,8(1)\n"
        "addi	1,1,16\n"
        "blr\n"
    );
    __builtin_unreachable();
}
