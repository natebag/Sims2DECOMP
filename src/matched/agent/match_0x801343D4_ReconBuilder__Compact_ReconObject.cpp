// 0x801343D4 ReconBuilder::Compact(ReconObject (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 25,0x54(1); stw 0,0x74(1); addi 27,1,8; mr 29,3; mr 28,4; mr 30,5; mr 31,6; mr 25,7; addi 4,27,8; li 5,64; mr 3,27; bl _s801343D4_0; mr 3,29; mr 5,30; mr 4,28; bl _s801343D4_1; mr. 26,3; bne 0f; li 3,-1; b 5f; 0:; lwz 9,0x0(28); lwz 11,0xc(31); lwz 0,0x1c(9); lha 3,0x18(9); addi 29,11,248; mtspr 8,0; lha 30,0xf8(11); add 3,28,3; add 30,31,30; blrl; lwz 0,0x4(29); mr 5,3; mr 3,30; mr 6,25; mr 7,27; li 8,0; mr 4,26; mtspr 8,0; blrl; mr 3,31; bl _s801343D4_2; mr. 30,3; beq 2f; lwz 0,0x8(26); cmpwi 0,0; beq 1f; bl _s801343D4_3; lwz 4,0x4(26); bl _s801343D4_4; 1:; bl _s801343D4_5; mr 4,26; bl _s801343D4_6; b 4f; 2:; lwz 9,0xc(31); mr 4,26; lha 3,0x108(9); lwz 0,0x10c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,31; bl _s801343D4_7; mr. 30,3; bne 3f; li 3,0; b 5f; 3:; lwz 9,0xc(31); mr 4,26; lha 3,0x110(9); lwz 0,0x114(9); add 3,31,3; mtspr 8,0; blrl; 4:; mr 3,30; 5:; lwz 0,0x74(1); mtspr 8,0; lmw 25,0x54(1); addi 1,1,112"
extern "C" void _s801343D4_0();
extern "C" void _s801343D4_1();
extern "C" void _s801343D4_2();
extern "C" void _s801343D4_3();
extern "C" void _s801343D4_4();
extern "C" void _s801343D4_5();
extern "C" void _s801343D4_6();
extern "C" void _s801343D4_7();
extern "C" void f_801343D4() {}
