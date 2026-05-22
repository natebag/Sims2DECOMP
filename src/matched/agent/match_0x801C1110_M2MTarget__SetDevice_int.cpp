// 0x801C1110 M2MTarget::SetDevice(int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32705; stw 4,0x10c(3); addi 3,9,8636; bl _s801C1110_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801C1110_0();
extern "C" void f_801C1110() {}
