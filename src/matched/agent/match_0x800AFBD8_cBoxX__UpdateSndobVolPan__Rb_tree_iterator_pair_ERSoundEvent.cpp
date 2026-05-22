// 0x800AFBD8 cBoxX::UpdateSndobVolPan(_Rb_tree_iterator<pair<ERSoundEvent (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,3; mr 31,4; lwz 3,-21492(13); bl _s800AFBD8_0; cmpwi 3,1; bne 3f; lwz 11,0x0(31); li 5,0; lwz 9,-24136(13); lwz 31,0x10(11); lwz 3,0x50(9); mr 4,31; bl _s800AFBD8_1; mr. 30,3; beq 3f; addi 5,1,8; addi 6,1,12; addi 7,1,16; addi 8,1,20; mr 4,31; mr 3,29; bl _s800AFBD8_2; lwz 3,0x8(1); addi 7,1,24; lwz 4,0xc(1); addi 8,1,28; lwz 5,0x10(1); lwz 6,0x14(1); bl _s800AFBD8_3; addi 3,29,48; li 9,0; lwz 0,0x4(3); cmpwi 0,0; bne 0f; lwz 0,0x8(3); cmpwi 0,0; beq 1f; 0:; li 9,1; 1:; cmpwi 9,0; beq 2f; mr 3,30; bl _s800AFBD8_4; cmpwi 3,2; beq 3f; 2:; lwz 4,0x18(1); mr 3,30; bl _s800AFBD8_5; lwz 4,0x1c(1); mr 3,30; bl _s800AFBD8_6; 3:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s800AFBD8_0();
extern "C" void _s800AFBD8_1();
extern "C" void _s800AFBD8_2();
extern "C" void _s800AFBD8_3();
extern "C" void _s800AFBD8_4();
extern "C" void _s800AFBD8_5();
extern "C" void _s800AFBD8_6();
extern "C" void f_800AFBD8() {}
