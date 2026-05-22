// 0x800A09E4 basic_string_ref2::basic_string_ref2(unsigned (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; mr 31,3; mr 29,4; cmpwi 30,-1; bne 0f; bl _s800A09E4_0; 0:; stw 30,0x4(31); cmpwi 30,0; stw 30,0x8(31); beq 3f; addi 30,30,1; stw 30,0x8(31); cmpwi 30,0; beq 1f; bl _s800A09E4_1; rlwinm 4,30,1,0,30; li 5,0; bl _s800A09E4_2; mr 0,3; b 2f; 1:; li 0,0; 2:; lwz 5,0x4(31); mr 4,29; mr 3,0; stw 0,0x0(31); rlwinm 5,5,1,0,30; bl _s800A09E4_3; lwz 30,0x4(31); bl _s800A09E4_4; lwz 9,0x0(31); add 30,30,30; sthx 3,30,9; b 4f; 3:; stw 30,0x0(31); 4:; li 0,1; mr 3,31; stw 0,0xc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A09E4_0();
extern "C" void _s800A09E4_1();
extern "C" void _s800A09E4_2();
extern "C" void _s800A09E4_3();
extern "C" void _s800A09E4_4();
extern "C" void f_800A09E4() {}
