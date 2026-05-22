// 0x80188BF4 HUDTarget::AddMenu(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,3; mr 30,4; mr 29,5; mr 28,6; mr 27,7; mr 26,8; bl _s80188BF4_0; mulli 30,30,180; mr 4,29; mr 5,28; mr 6,27; mr 7,26; addi 30,30,1856; add 3,25,30; bl _s80188BF4_1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80188BF4_0();
extern "C" void _s80188BF4_1();
extern "C" void f_80188BF4() {}
