// 0x802BC960 EAStringC::AppendFormat(char (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stmw 27,0x94(1); stw 0,0xac(1); lis 0,512; addi 11,1,176; addi 30,1,8; stw 0,0x80(1); stw 11,0x84(1); mr 28,3; stw 30,0x88(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; mr 27,4; mr 3,27; bl _s802BC960_0; lwz 9,0x0(28); addi 11,1,128; lwz 8,0x80(1); addi 10,1,112; lhz 29,0x2(9); rlwinm 31,3,2,0,29; lwz 0,0x8(11); lwz 9,0x4(11); stw 8,0x70(1); stw 0,0x8(10); stw 9,0x4(10); b 2f; 1:; add 31,31,31; 2:; add 4,29,31; mr 3,28; li 5,0; li 6,0; li 7,0; li 8,0; bl _s802BC960_1; lwz 9,0x0(28); mr 5,27; addi 6,1,112; lhz 4,0x4(9); addi 9,9,8; add 30,9,29; subf 4,29,4; mr 3,30; bl _s802BC960_2; mr. 3,3; blt 1b; li 0,0; add 10,29,3; stbx 0,30,3; li 8,0; lwz 9,0x0(28); sth 10,0x2(9); lwz 11,0x0(28); sth 8,0x6(11); lwz 0,0xac(1); mtspr 8,0; lmw 27,0x94(1); addi 1,1,168"
extern "C" void _s802BC960_0();
extern "C" void _s802BC960_1();
extern "C" void _s802BC960_2();
extern "C" void f_802BC960() {}
