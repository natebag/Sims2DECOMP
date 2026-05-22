// 0x801976C4 CASGeneticsTarget::~CASGeneticsTarget(void) (660 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 30,3; lis 9,-32698; lis 11,-32698; lwz 0,0x0(30); addi 9,9,28456; addi 11,11,28552; mr 23,4; stw 9,0x88(30); stw 11,0x80(30); cmpwi 0,0; beq 9f; lwz 3,0x4(30); addi 4,30,40; bl _s801976C4_0; lwz 3,0x8(30); addi 4,30,56; bl _s801976C4_1; lwz 3,0xc(30); addi 4,30,72; bl _s801976C4_2; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(30); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(30); bl _s801976C4_3; 2:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(30); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(30); bl _s801976C4_4; 5:; lwz 3,0x18(30); cmpwi 3,0; beq 6f; lwz 4,0x7c(30); bl _s801976C4_5; 6:; lwz 3,0x1c(30); cmpwi 3,0; beq 7f; lwz 4,0x7c(30); bl _s801976C4_6; 7:; lwz 3,0x20(30); cmpwi 3,0; beq 8f; lwz 4,0x7c(30); bl _s801976C4_7; 8:; lwz 3,0x24(30); cmpwi 3,0; beq 9f; lwz 4,0x7c(30); bl _s801976C4_8; 9:; lwz 3,0x94(30); cmpwi 3,0; beq 10f; li 4,3; bl _s801976C4_9; 10:; lwz 3,0x2f8(30); li 31,0; stw 31,0x94(30); cmpwi 3,0; beq 11f; li 4,3; bl _s801976C4_10; 11:; lwz 3,0x2fc(30); stw 31,0x2f8(30); cmpwi 3,0; beq 12f; li 4,3; bl _s801976C4_11; 12:; stw 31,0x2fc(30); addi 28,30,772; addi 27,30,788; addi 25,30,172; addi 24,30,132; li 26,0; li 31,0; li 29,4; 13:; lwzx 3,31,28; cmpwi 3,0; beq 14f; bl _s801976C4_12; stwx 26,31,28; 14:; addi 31,31,4; addic. 29,29,-1; bne 13b; li 28,0; li 31,0; li 29,2; 15:; lwzx 3,31,27; cmpwi 3,0; beq 16f; bl _s801976C4_13; stwx 28,31,27; 16:; addi 31,31,4; addic. 29,29,-1; bne 15b; lwz 4,0x414(30); cmpwi 4,0; beq 17f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26564(13); lwz 4,0x414(30); lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x414(30); 17:; lwz 3,0x418(30); bl _s801976C4_14; li 0,0; cmpwi 25,0; stw 0,0x418(30); beq 19f; addi 9,30,756; cmpw 25,9; beq 19f; mr 0,25; 18:; addi 9,9,-292; cmpw 0,9; bne 18b; 19:; lis 9,-32698; lis 11,-32698; addi 9,9,24424; addi 11,11,-12328; stw 9,0x4(24); andi. 0,23,1; stw 11,0x80(30); beq 20f; mr 3,30; bl _s801976C4_15; 20:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s801976C4_0();
extern "C" void _s801976C4_1();
extern "C" void _s801976C4_2();
extern "C" void _s801976C4_3();
extern "C" void _s801976C4_4();
extern "C" void _s801976C4_5();
extern "C" void _s801976C4_6();
extern "C" void _s801976C4_7();
extern "C" void _s801976C4_8();
extern "C" void _s801976C4_9();
extern "C" void _s801976C4_10();
extern "C" void _s801976C4_11();
extern "C" void _s801976C4_12();
extern "C" void _s801976C4_13();
extern "C" void _s801976C4_14();
extern "C" void _s801976C4_15();
extern "C" void f_801976C4() {}
