// 0x800A093C basic_string_ref2::basic_string_ref2(unsigned (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; stw 5,0x4(31); cmpwi 6,0; stw 6,0x8(31); beq 2f; addi 30,6,1; stw 30,0x8(31); cmpwi 30,0; beq 0f; bl _s800A093C_0; rlwinm 4,30,1,0,30; li 5,0; bl _s800A093C_1; b 1f; 0:; li 3,0; 1:; lwz 5,0x4(31); stw 3,0x0(31); cmpwi 5,0; beq 3f; mr 4,29; rlwinm 5,5,1,0,30; bl _s800A093C_2; lwz 30,0x4(31); bl _s800A093C_3; lwz 9,0x0(31); add 30,30,30; sthx 3,30,9; b 3f; 2:; stw 6,0x0(31); 3:; li 0,1; mr 3,31; stw 0,0xc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A093C_0();
extern "C" void _s800A093C_1();
extern "C" void _s800A093C_2();
extern "C" void _s800A093C_3();
extern "C" void f_800A093C() {}
