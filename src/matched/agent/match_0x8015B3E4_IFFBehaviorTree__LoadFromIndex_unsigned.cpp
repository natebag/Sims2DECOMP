// 0x8015B3E4 IFFBehaviorTree::LoadFromIndex(unsigned (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); lwz 9,-21508(13); mr 27,3; mr 26,4; mr 31,5; lwz 11,0x0(9); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; mr. 28,3; beq 0f; lwz 9,0xc(28); lis 4,16968; extsh 5,31; ori 4,4,16726; lha 3,0x90(9); li 6,0; lwz 0,0x94(9); add 3,28,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; lwz 0,0x4(31); li 30,0; stw 30,0x8(27); mr 4,31; stw 0,0x54(27); addi 5,27,12; addi 29,27,88; lwz 9,0xc(28); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0xc(28); addi 5,1,8; sth 30,0x8(1); mr 4,31; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,28,3; mtspr 8,0; blrl; lha 4,0x8(1); mr 3,27; bl _s8015B3E4_0; mr 4,26; mr 3,29; bl _s8015B3E4_1; lhz 4,0x8(1); mr 3,29; bl _s8015B3E4_2; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s8015B3E4_0();
extern "C" void _s8015B3E4_1();
extern "C" void _s8015B3E4_2();
extern "C" void f_8015B3E4() {}
