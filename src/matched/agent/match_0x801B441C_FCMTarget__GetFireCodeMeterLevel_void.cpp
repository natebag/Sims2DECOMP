// 0x801B441C FCMTarget::GetFireCodeMeterLevel(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 3,0; bl _s801B441C_0; lis 9,-32705; lfs f0,0x968(9); fmuls f1,f1,f0; fctiwz f13,f1; stfd f13,0x8(1); lwz 3,0xc(1); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s801B441C_0();
extern "C" void f_801B441C() {}
