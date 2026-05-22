// 0x8035B5B0 EFloatTree::InsertFixup(EFloatTreeNode (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x8(30); cmpw 31,0; beq 7f; lwz 11,0x8(31); lwz 0,0x14(11); cmpwi 0,1; bne 7f; li 29,0; li 28,1; 0:; lwz 10,0x8(11); lwz 9,0x0(10); cmpw 11,9; bne 2f; lwz 9,0x4(10); lwz 0,0x14(9); cmpwi 0,1; beq 3f; lwz 0,0x4(11); cmpw 31,0; bne 1f; mr 31,11; mr 3,30; mr 4,31; bl _s8035B5B0_0; 1:; lwz 11,0x8(31); mr 3,30; stw 29,0x14(11); lwz 9,0x8(31); lwz 11,0x8(9); stw 28,0x14(11); lwz 9,0x8(31); lwz 4,0x8(9); bl _s8035B5B0_1; b 6f; 2:; lwz 0,0x14(9); cmpwi 0,1; bne 4f; 3:; stw 29,0x14(11); stw 29,0x14(9); lwz 9,0x8(31); lwz 11,0x8(9); stw 0,0x14(11); lwz 9,0x8(31); lwz 31,0x8(9); b 6f; 4:; lwz 0,0x0(11); cmpw 31,0; bne 5f; mr 31,11; mr 3,30; mr 4,31; bl _s8035B5B0_2; 5:; lwz 11,0x8(31); mr 3,30; stw 29,0x14(11); lwz 9,0x8(31); lwz 11,0x8(9); stw 28,0x14(11); lwz 9,0x8(31); lwz 4,0x8(9); bl _s8035B5B0_3; 6:; lwz 0,0x8(30); cmpw 31,0; beq 7f; lwz 11,0x8(31); lwz 0,0x14(11); cmpwi 0,1; beq 0b; 7:; lwz 9,0x8(30); li 0,0; stw 0,0x14(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035B5B0_0();
extern "C" void _s8035B5B0_1();
extern "C" void _s8035B5B0_2();
extern "C" void _s8035B5B0_3();
extern "C" void f_8035B5B0() {}
