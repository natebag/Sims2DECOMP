// 0x80193B78 CASTarget::Update(void) (504 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 28,3; lwz 11,0x1350(28); cmpwi 11,0; beq 4f; lwz 9,0x4(11); lfs f1,-26800(13); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x104(28); cmpwi 0,3; bne 1f; addi 29,28,2632; addi 30,28,2636; li 31,4; 0:; lwz 9,0x0(30); lfs f1,-26800(13); addi 30,30,576; lha 3,0x58(9); lwz 0,0x5c(9); add 3,29,3; mtspr 8,0; addi 29,29,576; blrl; addic. 31,31,-1; bne 0b; b 2f; 1:; lwz 0,0x134c(28); lfs f1,-26800(13); rlwinm 3,0,3,0,28; add 3,3,0; rlwinm 3,3,6,0,25; add 9,3,28; lwz 11,0xa4c(9); addi 3,3,2632; add 3,28,3; lha 0,0x58(11); lwz 9,0x5c(11); add 3,3,0; mtspr 8,9; blrl; 2:; lwz 3,0x1354(28); cmpwi 3,0; beq 3f; lfs f1,-26800(13); bl _s80193B78_0; 3:; lwz 11,0x1370(28); cmpwi 11,0; beq 4f; lwz 9,0x80(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; 4:; lis 9,-32705; li 3,0; lfs f1,-15556(9); li 4,0; li 5,0; bl _s80193B78_1; lfs f1,-26800(13); bl _s80193B78_2; lwz 27,0x1364(28); cmpwi 27,1; bne 6f; lis 30,-32698; addi 29,1,8; addi 30,30,28616; li 0,3; stw 30,0x4(29); addi 31,28,216; stw 0,0x8(1); mr 3,31; mr 4,29; bl _s80193B78_3; stw 30,0x4(29); mr 3,29; li 4,2; bl _s80193B78_4; lwz 0,0x1348(28); rlwinm 0,0,25,31,31; cmpwi 0,0; beq 5f; lis 30,-32698; addi 29,1,16; addi 30,30,28648; stw 27,0x10(1); stw 30,0x14(1); mr 3,31; mr 4,29; stw 27,0x8(29); bl _s80193B78_5; stw 30,0x14(1); mr 3,29; li 4,2; bl _s80193B78_6; b 6f; 5:; lis 30,-32698; mr 3,31; addi 30,30,28648; mr 4,29; stw 30,0x4(29); stw 27,0x8(1); stw 0,0x8(29); bl _s80193B78_7; stw 30,0x4(29); mr 3,29; li 4,2; bl _s80193B78_8; 6:; lwz 0,0x1364(28); addic. 0,0,-1; bge 7f; li 0,0; 7:; stw 0,0x1364(28); lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s80193B78_0();
extern "C" void _s80193B78_1();
extern "C" void _s80193B78_2();
extern "C" void _s80193B78_3();
extern "C" void _s80193B78_4();
extern "C" void _s80193B78_5();
extern "C" void _s80193B78_6();
extern "C" void _s80193B78_7();
extern "C" void _s80193B78_8();
extern "C" void f_80193B78() {}
