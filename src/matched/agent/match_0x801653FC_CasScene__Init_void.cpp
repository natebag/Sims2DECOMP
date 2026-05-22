// 0x801653FC CasScene::Init(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x4(30); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,30,3; blrl; li 4,0; mr 3,30; bl _s801653FC_0; li 3,60; bl _s801653FC_1; li 4,0; bl _s801653FC_2; mr 0,3; li 4,1; stw 0,0xac0(30); bl _s801653FC_3; lwz 9,0x4(30); lwz 29,0xac0(30); lha 3,0x88(9); lwz 0,0x8c(9); add 3,30,3; mtspr 8,0; blrl; mr 4,3; mr 3,29; bl _s801653FC_4; lwz 3,0xac0(30); li 4,1; bl _s801653FC_5; lwz 3,0xac0(30); bl _s801653FC_6; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801653FC_0();
extern "C" void _s801653FC_1();
extern "C" void _s801653FC_2();
extern "C" void _s801653FC_3();
extern "C" void _s801653FC_4();
extern "C" void _s801653FC_5();
extern "C" void _s801653FC_6();
extern "C" void f_801653FC() {}
