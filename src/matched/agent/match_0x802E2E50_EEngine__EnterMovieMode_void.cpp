// 0x802E2E50 EEngine::EnterMovieMode(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s802E2E50_0; lwz 3,-22652(13); lwz 9,0x0(3); lha 0,0x108(9); lwz 9,0x10c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802E2E50_0();
extern "C" void f_802E2E50() {}
