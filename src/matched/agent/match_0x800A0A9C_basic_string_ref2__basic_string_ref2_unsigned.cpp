// 0x800A0A9C basic_string_ref2::basic_string_ref2(unsigned (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr. 29,4; beq 0f; mr 3,29; bl _s800A0A9C_0; stw 3,0x8(31); stw 3,0x4(31); b 1f; 0:; stw 29,0x4(31); stw 29,0x8(31); 1:; lwz 4,0x8(31); cmpwi 4,0; beq 4f; addi 30,4,1; stw 30,0x8(31); cmpwi 30,0; beq 2f; bl _s800A0A9C_1; rlwinm 4,30,1,0,30; li 5,0; bl _s800A0A9C_2; mr 0,3; b 3f; 2:; li 0,0; 3:; lwz 5,0x4(31); mr 4,29; mr 3,0; stw 0,0x0(31); rlwinm 5,5,1,0,30; bl _s800A0A9C_3; lwz 30,0x4(31); bl _s800A0A9C_4; lwz 9,0x0(31); add 30,30,30; sthx 3,30,9; b 5f; 4:; stw 4,0x0(31); 5:; li 0,1; mr 3,31; stw 0,0xc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A0A9C_0();
extern "C" void _s800A0A9C_1();
extern "C" void _s800A0A9C_2();
extern "C" void _s800A0A9C_3();
extern "C" void _s800A0A9C_4();
extern "C" void f_800A0A9C() {}
