// 0x801AD004 E2ETarget::RestorePreviousSettings(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lfs f1,-30444(13); bl _s801AD004_0; lfs f1,-30436(13); bl _s801AD004_1; lfs f1,-30432(13); bl _s801AD004_2; lfs f1,-30440(13); bl _s801AD004_3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AD004_0();
extern "C" void _s801AD004_1();
extern "C" void _s801AD004_2();
extern "C" void _s801AD004_3();
extern "C" void f_801AD004() {}
