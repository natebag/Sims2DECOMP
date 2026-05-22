// 0x8016226C CasMediator::SetCasMode(int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32706; stw 4,0x2c(3); addi 3,9,-3344; bl _s8016226C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8016226C_0();
extern "C" void f_8016226C() {}
