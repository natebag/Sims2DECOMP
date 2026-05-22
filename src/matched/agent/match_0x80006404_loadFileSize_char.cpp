// 0x80006404 _loadFileSize(char (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); lwz 11,-26824(13); mr 30,3; addi 31,1,8; addi 28,1,16; lwz 9,0x338(11); mr 27,4; lis 26,-32694; li 29,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,31; bl _s80006404_0; lis 4,-32707; mr 3,31; addi 4,4,-11604; bl _s80006404_1; mr 4,30; mr 3,31; bl _s80006404_2; lwz 5,0x8(1); lis 6,-32707; addi 6,6,-11596; addi 3,26,-10620; mr 4,28; lis 7,-32768; lis 8,-32768; li 9,0; bl _s80006404_3; cmpwi 3,0; beq 0f; lwz 11,0x10(1); li 4,0; li 5,2; lwz 9,0x28(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x10(1); lwz 9,0x28(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; bl _s80006404_4; mr 4,30; li 5,0; bl _s80006404_5; lwz 11,0x10(1); mr 29,3; li 4,0; li 5,0; lwz 9,0x28(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x10(1); mr 4,29; mr 5,30; lwz 9,0x28(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,26,-10620; mr 4,28; bl _s80006404_6; stw 30,0x0(27); 0:; lwz 4,0x8(1); mr 3,31; bl _s80006404_7; mr 3,29; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s80006404_0();
extern "C" void _s80006404_1();
extern "C" void _s80006404_2();
extern "C" void _s80006404_3();
extern "C" void _s80006404_4();
extern "C" void _s80006404_5();
extern "C" void _s80006404_6();
extern "C" void _s80006404_7();
extern "C" void f_80006404() {}
