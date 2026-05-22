// 0x802BC170 EAStringC::EAStringC(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 0f; addi 30,4,12; lwz 3,-23020(13); rlwinm 30,30,0,0,29; mr 4,30; bl _s802BC170_0; stw 3,0x0(31); li 0,1; sth 0,0x0(3); addi 30,30,-9; li 10,0; li 0,0; lwz 9,0x0(31); sth 30,0x4(9); lwz 11,0x0(31); sth 10,0x2(11); lwz 9,0x0(31); sth 10,0x6(9); lwz 11,0x0(31); stb 0,0x8(11); b 1f; 0:; lis 11,-32700; addi 0,11,-6476; stw 0,0x0(31); lhz 9,-6476(11); addi 9,9,1; sth 9,-6476(11); 1:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802BC170_0();
extern "C" void f_802BC170() {}
