// 0x802E2414 EApp::CreateAndStartAppThread(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x338(30); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,30,3; mtspr 8,0; blrl; mr 5,3; li 4,24; li 6,0; mr 3,30; bl _s802E2414_0; lis 9,-32702; mr 3,30; addi 9,9,-5916; stw 9,0x32c(30); bl _s802E2414_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E2414_0();
extern "C" void _s802E2414_1();
extern "C" void f_802E2414() {}
