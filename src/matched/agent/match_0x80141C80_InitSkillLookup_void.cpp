// 0x80141C80 InitSkillLookup(void) (1188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 26,-31848(13); li 3,64; bl _s80141C80_0; mr 31,3; li 0,0; mr 9,31; li 11,1; 0:; stw 0,0x0(9); cmpwi 11,0; addi 9,9,4; addi 11,11,-1; bne 0b; addi 9,31,8; li 11,1; addi 10,31,16; addi 8,31,32; addi 27,31,40; li 0,0; 1:; stw 0,0x0(9); cmpwi 11,0; addi 9,9,4; addi 11,11,-1; bne 1b; mr 9,10; li 11,1; li 0,0; 2:; stw 0,0x0(9); cmpwi 11,0; addi 9,9,4; addi 11,11,-1; bne 2b; li 0,0; mr 9,8; stw 0,0x1c(31); li 11,1; stw 0,0x18(31); 3:; stw 0,0x0(9); cmpwi 11,0; addi 9,9,4; addi 11,11,-1; bne 3b; li 11,3; mr 9,27; mtspr 9,11; li 0,0; 4:; stw 0,0x0(9); addi 9,9,4; bdnz 4b; li 28,2; li 25,0; li 29,8; 5:; lwzx 3,29,27; mr 30,28; addi 28,28,-1; bl _s80141C80_1; stwx 25,29,27; bl _s80141C80_2; stwx 3,29,27; cmpwi 30,0; addi 29,29,-4; bgt 5b; li 30,0; lwz 3,0x0(31); stw 30,0x34(31); stw 30,0x38(31); stw 30,0x3c(31); bl _s80141C80_3; stw 30,0x0(31); bl _s80141C80_4; stw 3,0x0(31); lwz 3,0x4(31); bl _s80141C80_5; stw 30,0x4(31); bl _s80141C80_6; stw 3,0x4(31); lwz 3,0x8(31); bl _s80141C80_7; stw 30,0x8(31); bl _s80141C80_8; stw 3,0x8(31); lwz 3,0xc(31); bl _s80141C80_9; stw 30,0xc(31); bl _s80141C80_10; stw 3,0xc(31); lwz 3,0x10(31); bl _s80141C80_11; stw 30,0x10(31); bl _s80141C80_12; stw 3,0x10(31); lwz 3,0x14(31); bl _s80141C80_13; stw 30,0x14(31); bl _s80141C80_14; stw 3,0x14(31); lwz 3,0x18(31); bl _s80141C80_15; stw 30,0x18(31); bl _s80141C80_16; stw 3,0x18(31); lwz 3,0x1c(31); bl _s80141C80_17; stw 30,0x1c(31); bl _s80141C80_18; stw 3,0x1c(31); lwz 3,0x20(31); bl _s80141C80_19; stw 30,0x20(31); bl _s80141C80_20; stw 3,0x20(31); lwz 3,0x24(31); bl _s80141C80_21; stw 30,0x24(31); bl _s80141C80_22; stw 3,0x24(31); lwz 3,0x34(31); bl _s80141C80_23; stw 30,0x34(31); bl _s80141C80_24; stw 3,0x34(31); lwz 3,0x38(31); bl _s80141C80_25; stw 30,0x38(31); bl _s80141C80_26; stw 3,0x38(31); lwz 3,0x3c(31); bl _s80141C80_27; stw 30,0x3c(31); bl _s80141C80_28; stw 3,0x3c(31); mr 4,26; lwz 11,0x0(31); li 5,150; stw 31,-31660(13); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,151; lwz 11,0x4(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,152; lwz 11,0x8(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,153; lwz 11,0xc(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,154; lwz 11,0x10(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,155; lwz 11,0x14(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,130; lwz 11,0x18(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,128; lwz 11,0x1c(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,156; lwz 11,0x20(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,157; lwz 11,0x24(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 30,-31660(13); mr 4,26; li 5,158; lwz 11,0x28(30); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x2c(30); mr 4,26; li 5,159; lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x30(30); mr 4,26; li 5,160; lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,179; lwz 11,0x34(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,180; lwz 11,0x38(10); lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-31660(13); mr 4,26; li 5,181; lwz 11,0x3c(10); lwz 9,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80141C80_0();
extern "C" void _s80141C80_1();
extern "C" void _s80141C80_2();
extern "C" void _s80141C80_3();
extern "C" void _s80141C80_4();
extern "C" void _s80141C80_5();
extern "C" void _s80141C80_6();
extern "C" void _s80141C80_7();
extern "C" void _s80141C80_8();
extern "C" void _s80141C80_9();
extern "C" void _s80141C80_10();
extern "C" void _s80141C80_11();
extern "C" void _s80141C80_12();
extern "C" void _s80141C80_13();
extern "C" void _s80141C80_14();
extern "C" void _s80141C80_15();
extern "C" void _s80141C80_16();
extern "C" void _s80141C80_17();
extern "C" void _s80141C80_18();
extern "C" void _s80141C80_19();
extern "C" void _s80141C80_20();
extern "C" void _s80141C80_21();
extern "C" void _s80141C80_22();
extern "C" void _s80141C80_23();
extern "C" void _s80141C80_24();
extern "C" void _s80141C80_25();
extern "C" void _s80141C80_26();
extern "C" void _s80141C80_27();
extern "C" void _s80141C80_28();
extern "C" void f_80141C80() {}
