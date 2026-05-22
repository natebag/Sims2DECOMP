// 0x800D4CFC NghResFile::IsSaveGameValid(char (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); li 0,1; mr 25,5; stw 0,0x0(25); lis 11,-32696; mr 26,3; li 23,0; lwz 9,0x6330(11); andi. 0,4,128; addi 9,9,24; lwz 28,0xc(9); lwz 24,0x8(9); beq 1f; oris 0,4,65535; ori 27,0,65280; b 2f; 0:; li 0,0; li 31,1; stw 0,0x0(25); b 5f; 1:; mr 27,4; 2:; bl _s800D4CFC_0; lis 29,-8531; mr 4,28; li 5,64; li 6,0; li 7,0; bl _s800D4CFC_1; ori 29,29,48879; mr 30,3; b 4f; 3:; lwz 3,-26384(13); mr 6,28; mr 7,24; mr 4,26; lwz 9,0x0(3); mr 5,27; mr 8,30; li 23,1; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; cmpwi 31,1; bne 0b; lwz 0,0x0(30); xor 0,0,29; subfic 9,0,0; adde 0,9,0; stw 0,0x0(25); b 5f; 4:; lwz 3,-26384(13); mr 4,26; mr 5,27; lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; cmpwi 31,1; beq 3b; 5:; bl _s800D4CFC_2; mr 4,30; bl _s800D4CFC_3; cmpwi 23,0; beq 6f; lwz 3,-26384(13); mr 4,26; mr 5,27; lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 6:; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s800D4CFC_0();
extern "C" void _s800D4CFC_1();
extern "C" void _s800D4CFC_2();
extern "C" void _s800D4CFC_3();
extern "C" void f_800D4CFC() {}
