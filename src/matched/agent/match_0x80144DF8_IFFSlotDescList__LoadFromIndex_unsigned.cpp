// 0x80144DF8 IFFSlotDescList::LoadFromIndex(unsigned (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lwz 11,-21508(13); mr 28,3; mr 27,4; mr 30,5; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; lis 4,21324; lwz 9,0xc(31); extsh 5,30; ori 4,4,20308; li 6,0; lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; mr. 29,3; beq 0f; lwz 9,0xc(31); mr 4,29; addi 5,28,4; addi 30,28,76; lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc(31); addi 5,1,8; mr 4,29; lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,31,3; blrl; mr 4,27; mr 3,30; bl _s80144DF8_0; lhz 4,0x8(1); mr 3,30; bl _s80144DF8_1; lis 5,21324; lha 6,0x8(1); addi 3,28,84; mr 4,31; ori 5,5,20308; li 7,0; bl _s80144DF8_2; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80144DF8_0();
extern "C" void _s80144DF8_1();
extern "C" void _s80144DF8_2();
extern "C" void f_80144DF8() {}
