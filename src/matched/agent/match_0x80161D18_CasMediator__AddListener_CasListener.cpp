// 0x80161D18 CasMediator::AddListener(CasListener (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,4; mr 29,3; addi 3,1,16; mr 4,29; stw 30,0x18(1); addi 5,1,24; bl _s80161D18_0; lwz 0,0x14(1); mr 4,29; lwz 9,0x10(1); stw 0,0xc(1); stw 9,0x8(1); lwz 9,0x4(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80161D18_0();
extern "C" void f_80161D18() {}
