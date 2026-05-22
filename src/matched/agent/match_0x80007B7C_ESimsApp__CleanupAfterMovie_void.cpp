// 0x80007B7C ESimsApp::CleanupAfterMovie(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80007DD8" lines="lwz 0,0x1cc(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,-32716(13); lis 11,-32707; lfs f21,-11244(11); addi 9,9,1; stw 9,-32716(13)"
extern "C" void f_80007DD8();
extern "C" void f_80007B7C() {}
