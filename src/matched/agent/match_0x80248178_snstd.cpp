// 0x80248178 snstd (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32731; lis 11,-32731; lis 10,-32731; lis 8,-32731; li 0,0; addi 9,9,-29696; addi 11,11,-29596; addi 10,10,-29484; addi 8,8,-29384; stw 6,0x5c(3); sth 4,0xc(3); sth 5,0xe(3); stw 0,0x18(3); stw 9,0x20(3); stw 11,0x24(3); stw 10,0x28(3); stw 8,0x2c(3); stw 0,0x0(3); stw 0,0x4(3); stw 0,0x8(3); stw 0,0x10(3); stw 3,0x1c(3)"
extern "C" void f_80248178() {}
