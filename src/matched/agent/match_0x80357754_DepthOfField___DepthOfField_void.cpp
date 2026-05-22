// 0x80357754 DepthOfField::~DepthOfField(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; andi. 0,4,1; addi 9,9,-10424; stw 9,0x10(3); beq 0f; bl _s80357754_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80357754_0();
extern "C" void f_80357754() {}
