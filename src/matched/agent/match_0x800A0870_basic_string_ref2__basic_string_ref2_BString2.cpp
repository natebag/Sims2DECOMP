// 0x800A0870 basic_string_ref2::basic_string_ref2(BString2 (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,4; mr 28,5; stw 6,0x4(31); cmpwi 6,0; stw 6,0x8(31); beq 4f; addi 30,6,1; stw 30,0x8(31); cmpwi 30,0; beq 0f; bl _s800A0870_0; rlwinm 4,30,1,0,30; li 5,0; bl _s800A0870_1; b 1f; 0:; li 3,0; 1:; stw 3,0x0(31); mr 3,29; bl _s800A0870_2; cmpwi 3,0; beq 2f; lwz 9,0x0(29); lwz 9,0x0(9); b 3f; 2:; li 9,0; 3:; lwz 5,0x4(31); add 4,28,28; lwz 3,0x0(31); add 4,4,9; rlwinm 5,5,1,0,30; bl _s800A0870_3; lwz 30,0x4(31); bl _s800A0870_4; lwz 9,0x0(31); add 30,30,30; sthx 3,30,9; b 5f; 4:; stw 6,0x0(31); 5:; li 0,1; mr 3,31; stw 0,0xc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A0870_0();
extern "C" void _s800A0870_1();
extern "C" void _s800A0870_2();
extern "C" void _s800A0870_3();
extern "C" void _s800A0870_4();
extern "C" void f_800A0870() {}
