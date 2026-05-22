// 0x802E2180 EApp::EApp(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s802E2180_0; lis 9,-32697; li 0,0; addi 9,9,-23000; stw 0,0x340(30); stw 9,0x338(30); mr 3,30; stw 0,0x450(30); stw 0,0x454(30); stw 0,0x458(30); stw 0,0x45c(30); stw 0,0x470(30); stw 30,-26824(13); stw 0,0x468(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E2180_0();
extern "C" void f_802E2180() {}
