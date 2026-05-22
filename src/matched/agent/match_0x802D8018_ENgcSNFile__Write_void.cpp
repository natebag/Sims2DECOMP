// 0x802D8018 ENgcSNFile::Write(void (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x2c(3); bl _s802D8018_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802D8018_0();
extern "C" void f_802D8018() {}
