// 0x802BC20C EAStringC::EAStringC(unsigned (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; mr. 29,5; beq 0f; addi 30,29,12; lwz 3,-23020(13); rlwinm 30,30,0,0,29; mr 4,30; bl _s802BC20C_0; stw 3,0x0(31); li 0,1; sth 0,0x0(3); addi 30,30,-9; mr 4,28; mr 5,29; lwz 9,0x0(31); sth 30,0x4(9); lwz 3,0x0(31); addi 3,3,8; bl _s802BC20C_1; lwz 9,0x0(31); li 0,0; sth 29,0x2(9); lwz 11,0x0(31); sth 0,0x6(11); lwz 9,0x0(31); addi 9,9,8; stbx 0,9,29; b 1f; 0:; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); 1:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802BC20C_0();
extern "C" void _s802BC20C_1();
extern "C" void f_802BC20C() {}
