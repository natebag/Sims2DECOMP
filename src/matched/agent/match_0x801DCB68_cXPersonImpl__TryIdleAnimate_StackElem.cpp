// 0x801DCB68 cXPersonImpl::TryIdleAnimate(StackElem (784 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x1e8(30); cmpwi 3,0; beq 0f; bl _s801DCB68_0; li 0,0; stw 0,0x1e8(30); 0:; cmpwi 28,0; beq 1f; lwz 5,0x8(28); cmpwi 5,0; beq 1f; lwz 0,0x0(30); lis 9,-32705; addi 4,9,20632; cmpwi 0,0; beq 4f; lwz 3,0x1c(30); cmpwi 3,0; beq 4f; lwz 6,0x7c(30); li 7,0; bl _s801DCB68_1; b 4f; 1:; lwz 11,0x4(29); cmpwi 11,0; beq 2f; lwz 3,0xc(11); addi 4,30,488; bl _s801DCB68_2; lwz 5,0x1e8(30); cmpwi 5,0; beq 3f; lwz 0,0x0(30); lis 9,-32705; addi 4,9,20632; cmpwi 0,0; beq 2f; lwz 3,0x1c(30); cmpwi 3,0; beq 2f; lwz 6,0x7c(30); li 7,0; bl _s801DCB68_3; 2:; lwz 0,0x1e8(30); cmpwi 0,0; bne 4f; 3:; lwz 0,0x0(30); lis 9,-32705; addi 4,9,20632; cmpwi 0,0; beq 4f; lwz 3,0x1c(30); cmpwi 3,0; beq 4f; lis 5,-24685; lwz 6,0x7c(30); ori 5,5,65396; li 7,0; bl _s801DCB68_4; 4:; lwz 0,-29696(13); cmpwi 0,0; bne 5f; addi 28,30,468; mr 3,28; bl _s801DCB68_5; lis 4,-32705; li 5,0; addi 4,4,20104; mr 3,28; bl _s801DCB68_6; li 4,16; mr 3,28; bl _s801DCB68_7; lis 4,-32705; li 5,0; addi 4,4,20120; mr 3,28; bl _s801DCB68_8; li 4,14; mr 3,28; bl _s801DCB68_9; lis 4,-32705; li 5,0; addi 4,4,20136; mr 3,28; bl _s801DCB68_10; li 4,14; mr 3,28; bl _s801DCB68_11; lis 4,-32705; li 5,0; addi 4,4,20160; mr 3,28; bl _s801DCB68_12; mr 3,28; li 4,14; bl _s801DCB68_13; mr 3,30; lwz 4,0xa0(3); bl _s801DCB68_14; lis 30,10922; mr 29,3; ori 30,30,43691; srawi 9,29,31; mulhw 30,29,30; lis 4,-32705; li 5,0; addi 4,4,20648; mr 3,28; subf 30,9,30; mulli 0,30,6; mulli 30,30,40; subf 29,0,29; mulli 29,29,40; bl _s801DCB68_15; mr 4,30; mr 3,28; bl _s801DCB68_16; mr 3,28; mr 4,29; bl _s801DCB68_17; mr 3,28; bl _s801DCB68_18; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; lwz 0,0xa4(3); li 3,-1; mulli 0,0,6; subf 4,0,4; cmplwi 4,6; bgtlr; mr 3,4; blr; lwz 0,0xa4(3); mulli 0,0,6; add. 4,4,0; blt 6f; lwz 0,0x9c(3); cmpw 4,0; blt 7f; 6:; li 3,-1; blr; 7:; mr 3,4; blr; mr 11,3; lwz 0,0xa8(11); mulli 9,0,6; cmpwi 0,0; add 3,4,9; blt 8f; cmpwi 3,0; blt 8f; lwz 0,0x9c(11); cmpw 3,0; bltlr; 8:; li 3,-1; blr; lwz 0,0xa4(3); li 3,1; cmpwi 0,0; bgtlr; li 3,0; blr; mr 9,3; lwz 11,0xa4(9); li 3,1; lwz 0,0x9c(9); addi 11,11,1; mulli 11,11,6; subf. 9,11,0; bgtlr; li 3,0; blr; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; cmpwi 4,0; stw 0,0xb8(3); bne 9f; lis 5,-32705; lwz 4,0x94(3); addi 6,3,132; addi 5,5,20668; addi 3,3,324; li 7,0; li 8,0; bl _s801DCB68_19; 9:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801DCB68_0();
extern "C" void _s801DCB68_1();
extern "C" void _s801DCB68_2();
extern "C" void _s801DCB68_3();
extern "C" void _s801DCB68_4();
extern "C" void _s801DCB68_5();
extern "C" void _s801DCB68_6();
extern "C" void _s801DCB68_7();
extern "C" void _s801DCB68_8();
extern "C" void _s801DCB68_9();
extern "C" void _s801DCB68_10();
extern "C" void _s801DCB68_11();
extern "C" void _s801DCB68_12();
extern "C" void _s801DCB68_13();
extern "C" void _s801DCB68_14();
extern "C" void _s801DCB68_15();
extern "C" void _s801DCB68_16();
extern "C" void _s801DCB68_17();
extern "C" void _s801DCB68_18();
extern "C" void _s801DCB68_19();
extern "C" void f_801DCB68() {}
