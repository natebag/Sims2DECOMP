// 0x8035BA58 EFloatTree::RemoveFixup(EFloatTreeNode (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x8(30); cmpw 31,0; beq 11f; lwz 0,0x14(31); cmpwi 0,0; bne 11f; li 29,0; li 28,1; 0:; lwz 9,0x8(31); lwz 4,0x0(9); cmpw 31,4; bne 4f; lwz 11,0x4(9); lwz 0,0x14(11); cmpwi 0,1; bne 1f; stw 29,0x14(11); mr 3,30; lwz 9,0x8(31); stw 0,0x14(9); lwz 4,0x8(31); bl _s8035BA58_0; lwz 9,0x8(31); lwz 11,0x4(9); 1:; lwz 10,0x0(11); lwz 0,0x14(10); cmpwi 0,0; bne 2f; lwz 9,0x4(11); lwz 0,0x14(9); cmpwi 0,0; bne 3f; b 6f; 2:; lwz 9,0x4(11); lwz 0,0x14(9); cmpwi 0,0; bne 3f; stw 0,0x14(10); mr 4,11; stw 28,0x14(11); mr 3,30; bl _s8035BA58_1; lwz 9,0x8(31); lwz 11,0x4(9); 3:; lwz 9,0x8(31); mr 3,30; lwz 0,0x14(9); stw 0,0x14(11); lwz 9,0x8(31); stw 29,0x14(9); lwz 11,0x4(11); stw 29,0x14(11); lwz 4,0x8(31); bl _s8035BA58_2; b 9f; 4:; mr 11,4; lwz 0,0x14(11); cmpwi 0,1; bne 5f; stw 29,0x14(11); mr 3,30; lwz 9,0x8(31); stw 0,0x14(9); lwz 4,0x8(31); bl _s8035BA58_3; lwz 9,0x8(31); lwz 11,0x0(9); 5:; lwz 10,0x4(11); lwz 0,0x14(10); cmpwi 0,0; bne 7f; lwz 9,0x0(11); lwz 0,0x14(9); cmpwi 0,0; bne 8f; 6:; stw 28,0x14(11); lwz 31,0x8(31); b 10f; 7:; lwz 9,0x0(11); lwz 0,0x14(9); cmpwi 0,0; bne 8f; stw 0,0x14(10); mr 4,11; stw 28,0x14(11); mr 3,30; bl _s8035BA58_4; lwz 9,0x8(31); lwz 11,0x0(9); 8:; lwz 9,0x8(31); mr 3,30; lwz 0,0x14(9); stw 0,0x14(11); lwz 9,0x8(31); stw 29,0x14(9); lwz 11,0x0(11); stw 29,0x14(11); lwz 4,0x8(31); bl _s8035BA58_5; 9:; lwz 31,0x8(30); 10:; lwz 0,0x8(30); cmpw 31,0; beq 11f; lwz 0,0x14(31); cmpwi 0,0; beq 0b; 11:; li 0,0; stw 0,0x14(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035BA58_0();
extern "C" void _s8035BA58_1();
extern "C" void _s8035BA58_2();
extern "C" void _s8035BA58_3();
extern "C" void _s8035BA58_4();
extern "C" void _s8035BA58_5();
extern "C" void f_8035BA58() {}
