// 0x80032E34 ESimShadow::DrawShadow(ELevelDrawData (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80032E34_0; lwz 11,0x320(30); lwz 9,0x4(11); lha 3,0x188(9); lwz 0,0x18c(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,0x98(29); bl _s80032E34_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80032E34_0();
extern "C" void _s80032E34_1();
extern "C" void f_80032E34() {}
