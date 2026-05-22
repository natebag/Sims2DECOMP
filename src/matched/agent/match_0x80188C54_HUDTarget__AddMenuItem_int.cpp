// 0x80188C54 HUDTarget::AddMenuItem(int, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 23,3; mr 30,4; mr 29,5; mr 28,6; mr 27,7; mr 26,8; mr 25,9; lwz 24,0x38(1); bl _s80188C54_0; mulli 30,30,180; mr 4,29; mr 5,28; mr 6,27; mr 7,26; mr 8,25; mr 9,24; addi 30,30,1856; add 3,23,30; bl _s80188C54_1; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s80188C54_0();
extern "C" void _s80188C54_1();
extern "C" void f_80188C54() {}
