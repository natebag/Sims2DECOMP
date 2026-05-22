// 0x801D1B7C sort_selectors_by_name(void (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,4; cmpw 3,31; bne 0f; li 3,0; b 5f; 0:; lwz 3,0x14(3); bl _s801D1B7C_0; mr 30,3; lwz 3,0x14(31); bl _s801D1B7C_1; mr 31,3; mr 4,30; addi 3,1,8; crxor 6,6,6; bl _s801D1B7C_2; lwz 9,0x8(1); li 3,0; cmpwi 9,0; beq 1f; lwz 3,0x0(9); 1:; mr 30,3; mr 4,31; addi 3,1,12; crxor 6,6,6; bl _s801D1B7C_3; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; lhz 0,0x0(30); cmpwi 0,34; bne 3f; addi 30,30,2; 3:; lhz 0,0x0(4); cmpwi 0,34; bne 4f; addi 4,4,2; 4:; mr 3,30; bl _s801D1B7C_4; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s801D1B7C_0();
extern "C" void _s801D1B7C_1();
extern "C" void _s801D1B7C_2();
extern "C" void _s801D1B7C_3();
extern "C" void _s801D1B7C_4();
extern "C" void f_801D1B7C() {}
