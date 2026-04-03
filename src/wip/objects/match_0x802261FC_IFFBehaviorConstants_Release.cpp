// 0x802261FC (92 bytes)
// IFFBehaviorConstants::Release(void)

__attribute__((noreturn))
void IFFBehaviorConstants::Release(void) {
    __asm__ __volatile__(
        "stwu	1,-8(1)\n"
        "mflr	0\n"
        "stw	0,12(1)\n"
        "mr	11,3\n"
        "lwz	9,96(11)\n"
        "addi	3,9,-1\n"
        "stw	3,96(11)\n"
        "cmpwi	3,0\n"
        "bne	.L_8015A674\n"
        "cmpwi	11,0\n"
        "beq	.L_8015A670\n"
        "lwz	9,0(11)\n"
        "li	4,3\n"
        "lha	3,112(9)\n"
        "lwz	0,116(9)\n"
        "add	3,11,3\n"
        "mtlr	0\n"
        "blrl\n"
        ".L_8015A670:\n"
        "li	3,0\n"
        ".L_8015A674:\n"
        "lwz	0,12(1)\n"
        "mtlr	0\n"
        "addi	1,1,8\n"
        "blr\n"
    );
    __builtin_unreachable();
}
