// 0x800C03A0 IFFResFile2::MoveBlock(unsigned (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 24,3; mr 25,7; mr. 5,5; bne 0f; li 3,0; b 4f; 0:; mr 28,4; mr. 30,6; subf 26,5,28; ble 3f; li 27,0; ori 27,27,51200; 1:; stw 27,0x8(1); cmpw 27,30; ble 2f; stw 30,0x8(1); 2:; addi 31,24,16; mr 4,28; mr 3,31; bl _s800C03A0_0; mr. 3,3; bne 4f; addi 29,1,8; mr 3,31; mr 4,25; mr 5,29; bl _s800C03A0_1; mr. 3,3; bne 4f; mr 3,31; mr 4,26; bl _s800C03A0_2; mr. 3,3; bne 4f; mr 3,31; mr 5,29; mr 4,25; bl _s800C03A0_3; mr. 3,3; bne 4f; lwz 0,0x8(1); add 28,28,0; add 26,26,0; subf. 30,0,30; bgt 1b; 3:; li 3,0; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s800C03A0_0();
extern "C" void _s800C03A0_1();
extern "C" void _s800C03A0_2();
extern "C" void _s800C03A0_3();
extern "C" void f_800C03A0() {}
