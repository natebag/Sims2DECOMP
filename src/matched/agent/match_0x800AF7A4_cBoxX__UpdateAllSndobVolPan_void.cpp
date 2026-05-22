// 0x800AF7A4 cBoxX::UpdateAllSndobVolPan(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 29,0x44(1); stw 0,0x54(1); mr 29,3; lwz 3,-21492(13); bl _s800AF7A4_0; cmpwi 3,1; bne 6f; addi 9,29,32; lwz 11,0x4(9); lwz 11,0x8(11); stw 11,0x8(1); lwz 0,0x4(9); cmpw 11,0; stw 0,0x10(1); beq 7f; mr 3,11; stw 11,0x18(1); stw 11,0x20(1); stw 11,0x30(1); bl _s800AF7A4_1; lwz 0,0x30(1); stw 3,0x20(1); stw 0,0x28(1); b 4f; 0:; lwz 10,0x20(1); addi 31,1,40; lwz 9,0x10(9); addi 30,1,48; lwz 0,0x10(10); cmpw 0,9; bne 3f; 1:; lwz 0,0x10(1); li 9,1; cmpw 10,0; bne 2f; li 9,0; 2:; cmpwi 9,0; beq 3f; mr 3,10; stw 10,0x38(1); bl _s800AF7A4_2; lwz 0,0x38(1); mr 10,3; stw 3,0x20(1); stw 0,0x28(1); lwz 9,0x18(1); lwz 11,0x10(10); lwz 0,0x10(9); cmpw 11,0; beq 1b; 3:; lwz 0,0x18(1); mr 4,31; lwz 9,0x20(1); mr 5,30; stw 0,0x28(1); mr 3,29; stw 9,0x30(1); bl _s800AF7A4_3; lwz 0,0x20(1); stw 0,0x18(1); 4:; lwz 9,0x18(1); li 11,1; lwz 0,0x10(1); cmpw 9,0; bne 5f; li 11,0; 5:; cmpwi 11,0; bne 0b; 6:; mr 3,29; bl _s800AF7A4_4; 7:; lwz 0,0x54(1); mtspr 8,0; lmw 29,0x44(1); addi 1,1,80"
extern "C" void _s800AF7A4_0();
extern "C" void _s800AF7A4_1();
extern "C" void _s800AF7A4_2();
extern "C" void _s800AF7A4_3();
extern "C" void _s800AF7A4_4();
extern "C" void f_800AF7A4() {}
