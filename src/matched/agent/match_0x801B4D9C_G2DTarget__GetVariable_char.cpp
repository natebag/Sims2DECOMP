// 0x801B4D9C G2DTarget::GetVariable(char (528 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,4; mr 31,3; lbz 3,0x0(30); extsb 3,3; bl _s801B4D9C_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,128; bl _s801B4D9C_1; mr 26,3; li 0,0; lis 3,-32705; stb 0,0x0(26); addi 3,3,2768; mr 4,30; bl _s801B4D9C_2; cmpwi 3,0; bne 1f; lis 9,-32705; li 27,1; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); mr 3,31; lhz 0,0x4(11); lis 29,-32705; stw 10,0x0(26); addi 30,31,312; sth 0,0x4(26); lis 28,-32705; stb 8,0x6(26); stw 27,0x88(31); bl _s801B4D9C_3; addi 3,29,2780; bl _s801B4D9C_4; stw 3,0x14c(31); li 4,0; addi 3,29,2780; bl _s801B4D9C_5; mr 3,31; bl _s801B4D9C_6; mr 3,30; bl _s801B4D9C_7; li 5,0; mr 3,30; addi 4,28,2804; bl _s801B4D9C_8; mr 3,30; li 4,1; bl _s801B4D9C_9; li 4,0; mr 3,30; bl _s801B4D9C_10; mr 3,30; bl _s801B4D9C_11; lis 7,-32705; li 6,0; li 8,0; addi 7,7,2808; li 5,175; addi 4,28,2804; mr 3,30; bl _s801B4D9C_12; mr 3,30; li 4,255; bl _s801B4D9C_13; mr 3,30; bl _s801B4D9C_14; li 0,2; stw 27,0x8c(31); stw 0,0x134(31); b 7f; 1:; lis 3,-32705; mr 4,30; addi 3,3,2828; bl _s801B4D9C_15; cmpwi 3,0; bne 2f; lis 4,-32705; mr 3,26; addi 4,4,-5236; li 5,352; crxor 6,6,6; bl _s801B4D9C_16; b 7f; 2:; lis 3,-32705; mr 4,30; addi 3,3,2848; bl _s801B4D9C_17; cmpwi 3,0; bne 3f; lwz 5,0xd4(31); b 4f; 3:; lis 3,-32705; mr 4,30; addi 3,3,2868; bl _s801B4D9C_18; cmpwi 3,0; bne 6f; lwz 0,0xa4(31); cmpwi 0,0; beq 5f; lwz 5,0xd8(31); 4:; lis 4,-32705; addi 4,4,-5236; mr 3,26; addi 5,5,32; crxor 6,6,6; bl _s801B4D9C_19; b 7f; 5:; lis 9,-32705; lhz 0,-5284(9); sth 0,0x0(26); b 7f; 6:; lis 3,-32705; mr 4,30; addi 3,3,2888; crxor 6,6,6; bl _s801B4D9C_20; 7:; mr 3,26; bl _s801B4D9C_21; mr 3,26; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801B4D9C_0();
extern "C" void _s801B4D9C_1();
extern "C" void _s801B4D9C_2();
extern "C" void _s801B4D9C_3();
extern "C" void _s801B4D9C_4();
extern "C" void _s801B4D9C_5();
extern "C" void _s801B4D9C_6();
extern "C" void _s801B4D9C_7();
extern "C" void _s801B4D9C_8();
extern "C" void _s801B4D9C_9();
extern "C" void _s801B4D9C_10();
extern "C" void _s801B4D9C_11();
extern "C" void _s801B4D9C_12();
extern "C" void _s801B4D9C_13();
extern "C" void _s801B4D9C_14();
extern "C" void _s801B4D9C_15();
extern "C" void _s801B4D9C_16();
extern "C" void _s801B4D9C_17();
extern "C" void _s801B4D9C_18();
extern "C" void _s801B4D9C_19();
extern "C" void _s801B4D9C_20();
extern "C" void _s801B4D9C_21();
extern "C" void f_801B4D9C() {}
