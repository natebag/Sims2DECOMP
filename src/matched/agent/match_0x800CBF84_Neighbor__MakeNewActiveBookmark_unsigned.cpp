// 0x800CBF84 Neighbor::MakeNewActiveBookmark(unsigned (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 26,0x18(1); stw 0,0x34(1); stw 12,0x14(1); subfic 28,4,3; subfe 28,28,28; neg. 28,28; mr 30,3; rlwinm 4,4,2,0,29; addi 9,30,408; li 0,0; mcrf cr4,cr0; stwx 0,9,4; mr 26,4; mr 27,9; li 29,0; 0:; bne cr4,1f; mr 3,30; li 4,0; li 5,1; bl _s800CBF84_0; mr 29,3; 1:; cmpwi 29,0; bne 2f; mr 3,30; mr 4,28; li 5,0; bl _s800CBF84_1; mr. 29,3; beq 3f; 2:; stwx 29,27,26; mr 3,29; bl _s800CBF84_2; b 5f; 3:; addi 4,1,8; addi 5,1,12; mr 3,28; bl _s800CBF84_3; lwz 4,0x8(1); mr 3,30; lwz 5,0xc(1); bl _s800CBF84_4; mr. 31,3; bge 4f; li 3,0; b 10f; 4:; mulli 0,31,12; lwz 3,0x194(30); add 3,3,0; bl _s800CBF84_5; mr 4,31; mr 3,30; bl _s800CBF84_6; 5:; cmpwi 29,0; beq 0b; mr 3,29; bl _s800CBF84_7; cmpwi 3,0; bne 9f; mr 3,29; bl _s800CBF84_8; cmpwi 3,0; beq 9f; li 28,0; addi 27,30,408; li 31,0; 6:; lwzx 3,31,27; cmpwi 3,0; beq 8f; lwz 0,0x4(3); li 9,1; cmpwi 0,0; bne 7f; li 9,0; 7:; cmpwi 9,0; beq 8f; bl _s800CBF84_9; cmpwi 3,0; bne 8f; lwzx 3,31,27; mr 4,29; bl _s800CBF84_10; cmpwi 3,0; beq 8f; mr 3,30; mr 4,28; bl _s800CBF84_11; 8:; addi 28,28,1; addi 31,31,4; cmplwi 28,6; ble 6b; 9:; mr 3,29; 10:; lwz 0,0x34(1); lwz 12,0x14(1); mtspr 8,0; lmw 26,0x18(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s800CBF84_0();
extern "C" void _s800CBF84_1();
extern "C" void _s800CBF84_2();
extern "C" void _s800CBF84_3();
extern "C" void _s800CBF84_4();
extern "C" void _s800CBF84_5();
extern "C" void _s800CBF84_6();
extern "C" void _s800CBF84_7();
extern "C" void _s800CBF84_8();
extern "C" void _s800CBF84_9();
extern "C" void _s800CBF84_10();
extern "C" void _s800CBF84_11();
extern "C" void f_800CBF84() {}
