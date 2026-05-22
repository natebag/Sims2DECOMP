// 0x801832A8 ActionMenu::ActionMenu(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; addi 30,31,12; mr 3,30; bl _s801832A8_0; li 0,1; li 9,0; stb 0,0x8(31); li 11,0; li 0,7; stb 11,0x9(31); mtspr 9,0; stw 30,0x70(31); sth 9,0x90(31); li 8,0; stw 9,0x0(31); addi 10,31,146; sth 9,0x4(31); addi 11,31,116; sth 9,0x6(31); stw 9,0xb0(31); 0:; stw 8,0x0(11); sth 8,0x0(10); addi 11,11,4; addi 10,10,2; bdnz 0b; li 0,0; li 9,0; stb 0,0xa1(31); mr 3,31; stw 9,0xa4(31); stb 0,0xa0(31); stb 0,0xa2(31); stw 9,0xac(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801832A8_0();
extern "C" void f_801832A8() {}
