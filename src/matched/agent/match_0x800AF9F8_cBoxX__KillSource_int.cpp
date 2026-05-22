// 0x800AF9F8 cBoxX::KillSource(int) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); mr 29,3; mr 28,4; addi 11,29,32; lwz 9,0x4(11); lwz 0,0x8(9); stw 0,0x8(1); lwz 9,0x4(11); stw 0,0x18(1); stw 9,0x10(1); b 3f; 0:; lwz 0,0x14(9); cmpw 0,28; bne 2f; lwz 30,0x10(9); mr 3,9; stw 9,0x20(1); addi 31,29,32; stw 9,0x30(1); bl _s800AF9F8_0; lwz 0,0x20(1); stw 3,0x18(1); stw 0,0x28(1); mr 3,0; stw 0,0x38(1); lwz 5,0x4(31); addi 6,5,12; addi 4,5,4; addi 5,5,8; bl _s800AF9F8_1; mr. 3,3; beq 1f; li 4,24; bl _s800AF9F8_2; 1:; lwz 9,0x8(31); mr 4,30; mr 3,29; addi 9,9,-1; stw 9,0x8(31); bl _s800AF9F8_3; b 3f; 2:; mr 3,9; stw 9,0x28(1); bl _s800AF9F8_4; lwz 0,0x28(1); stw 3,0x18(1); stw 0,0x20(1); 3:; lwz 9,0x18(1); li 11,1; lwz 0,0x10(1); cmpw 9,0; bne 4f; li 11,0; 4:; cmpwi 11,0; bne 0b; lwz 3,-21492(13); mr 4,28; bl _s800AF9F8_5; lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"
extern "C" void _s800AF9F8_0();
extern "C" void _s800AF9F8_1();
extern "C" void _s800AF9F8_2();
extern "C" void _s800AF9F8_3();
extern "C" void _s800AF9F8_4();
extern "C" void _s800AF9F8_5();
extern "C" void f_800AF9F8() {}
