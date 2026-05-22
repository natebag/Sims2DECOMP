// 0x800D4348 NghResFile::findListByResType(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; mr 3,31; li 29,0; bl _s800D4348_0; mr. 3,3; blt 0f; lwz 9,0x138(30); b 2f; 0:; mr 3,31; bl _s800D4348_1; mr. 3,3; blt 1f; lwz 0,0x24(30); addi 11,30,316; rlwinm 10,3,2,0,29; rlwinm 0,0,2,0,29; lwzx 9,11,0; add 29,9,10; b 3f; 1:; mr 3,31; bl _s800D4348_2; mr. 3,3; blt 3f; lwz 9,0x17c(30); 2:; rlwinm 0,3,2,0,29; add 29,9,0; 3:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800D4348_0();
extern "C" void _s800D4348_1();
extern "C" void _s800D4348_2();
extern "C" void f_800D4348() {}
