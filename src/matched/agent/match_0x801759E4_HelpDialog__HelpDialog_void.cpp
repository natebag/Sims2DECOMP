// 0x801759E4 HelpDialog::HelpDialog(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 30,3; li 29,0; lis 9,-32698; li 11,1; addi 9,9,30832; li 0,-1; addi 27,30,40; stw 29,0x0(30); stw 29,0x4(30); mr 3,27; stw 29,0x8(30); addi 26,30,48; stw 29,0xc(30); addi 25,30,52; stw 29,0x10(30); addi 24,30,56; stw 29,0x1c(30); lis 28,-32706; stw 29,0x20(30); stw 29,0x24(30); stw 9,0x84(30); stw 11,0x14(30); stw 0,0x18(30); bl _s801759E4_0; addi 3,30,44; bl _s801759E4_1; mr 3,26; bl _s801759E4_2; mr 3,25; bl _s801759E4_3; mr 3,24; bl _s801759E4_4; li 0,3; addi 9,30,80; stw 0,0x4c(30); addi 11,30,96; stw 29,0x3c(30); addi 10,30,112; stw 29,0x40(30); addi 4,28,8816; stw 29,0x44(30); mr 3,27; sth 29,0x48(30); sth 29,0x4a(30); stw 29,0x8(9); stw 29,0x50(30); stw 29,0x8(11); stw 29,0x60(30); stw 29,0x8(10); stw 29,0x70(30); bl _s801759E4_5; addi 4,28,8816; mr 3,26; bl _s801759E4_6; addi 4,28,8816; mr 3,25; bl _s801759E4_7; mr 3,24; addi 4,28,8816; bl _s801759E4_8; lis 9,-32698; stw 29,0x88(30); addi 9,9,25808; mr 3,30; stw 9,0x84(30); stw 29,0x8c(30); lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s801759E4_0();
extern "C" void _s801759E4_1();
extern "C" void _s801759E4_2();
extern "C" void _s801759E4_3();
extern "C" void _s801759E4_4();
extern "C" void _s801759E4_5();
extern "C" void _s801759E4_6();
extern "C" void _s801759E4_7();
extern "C" void _s801759E4_8();
extern "C" void f_801759E4() {}
