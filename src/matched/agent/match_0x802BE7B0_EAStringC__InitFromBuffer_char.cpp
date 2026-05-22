// 0x802BE7B0 EAStringC::InitFromBuffer(char (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 31,3; lbz 0,0x0(28); cmpwi 0,0; bne 0f; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); b 1f; 0:; mr 3,28; bl _s802BE7B0_0; mr 29,3; addi 30,29,12; lwz 3,-23020(13); rlwinm 30,30,0,0,29; mr 4,30; bl _s802BE7B0_1; stw 3,0x0(31); li 0,1; sth 0,0x0(3); addi 30,30,-9; li 10,0; mr 4,28; lwz 9,0x0(31); addi 5,29,1; sth 30,0x4(9); lwz 11,0x0(31); sth 29,0x2(11); lwz 9,0x0(31); sth 10,0x6(9); lwz 3,0x0(31); addi 3,3,8; crxor 6,6,6; bl _s802BE7B0_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802BE7B0_0();
extern "C" void _s802BE7B0_1();
extern "C" void _s802BE7B0_2();
extern "C" void f_802BE7B0() {}
