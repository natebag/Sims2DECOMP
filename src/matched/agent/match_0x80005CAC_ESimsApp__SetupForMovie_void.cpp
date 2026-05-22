// 0x80005CAC ESimsApp::SetupForMovie(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; addi 3,3,24012; bl _s80005CAC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80005CAC_0();
extern "C" void f_80005CAC() {}
