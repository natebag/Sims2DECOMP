// 0x8013E0F4 SeqResFile::Open(StringBuffer (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 28,3; mr 26,4; lwz 9,0xc(28); li 27,0; li 30,-250; lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,28,3; blrl; addi 10,28,208; li 0,0; lwzx 9,10,27; stw 0,0x8(1); cmpwi 9,0; beq 5f; lis 9,-32698; lis 11,-32698; addi 24,9,-2920; addi 25,11,-2896; mr 29,10; 0:; lwz 0,0x0(29); li 31,0; cmpwi 0,2; beq 1f; cmpwi 0,3; beq 2f; b 3f; 1:; li 3,336; bl _s8013E0F4_0; bl _s8013E0F4_1; mr 31,3; b 3f; 2:; li 3,336; bl _s8013E0F4_2; mr 30,3; mr 31,30; bl _s8013E0F4_3; stw 24,0x134(30); stw 25,0xc(30); 3:; mr 3,28; mr 4,31; mr 5,26; mr 6,27; addi 7,1,8; bl _s8013E0F4_4; lwz 0,0x0(29); mr 30,3; cmpwi 0,2; bne 4f; lis 5,16968; mr 3,28; mr 4,31; ori 5,5,16726; bl _s8013E0F4_5; lis 5,20559; mr 3,28; mr 4,31; ori 5,5,21321; bl _s8013E0F4_6; lis 5,21586; mr 3,28; mr 4,31; ori 5,5,17733; bl _s8013E0F4_7; lis 5,21584; mr 4,31; mr 3,28; ori 5,5,21072; bl _s8013E0F4_8; 4:; lwzu 0,0x14(29); addi 27,27,1; cmpwi 0,0; bne 0b; 5:; lwz 0,0x8(1); li 3,0; cmpwi 0,0; bne 6f; mr 3,30; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"
extern "C" void _s8013E0F4_0();
extern "C" void _s8013E0F4_1();
extern "C" void _s8013E0F4_2();
extern "C" void _s8013E0F4_3();
extern "C" void _s8013E0F4_4();
extern "C" void _s8013E0F4_5();
extern "C" void _s8013E0F4_6();
extern "C" void _s8013E0F4_7();
extern "C" void _s8013E0F4_8();
extern "C" void f_8013E0F4() {}
