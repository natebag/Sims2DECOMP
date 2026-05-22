// 0x80110D44 ObjSelector::GetThumbnail(ERShader (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 0,0x94(31); cmpwi 0,0; bne 7f; lwz 4,0x90(31); cmpwi 4,0; beq 0f; lwz 4,0xc(4); cmpwi 4,0; beq 7f; lis 3,-32692; li 5,0; addi 3,3,-17444; li 6,0; bl _s80110D44_0; stw 3,0x94(31); b 7f; 0:; lwz 0,0x8c(31); cmpwi 0,0; beq 7f; mr 3,31; bl _s80110D44_1; li 4,0; bl _s80110D44_2; mr. 4,3; beq 4f; lis 3,-32692; li 5,0; addi 3,3,-17444; li 6,0; bl _s80110D44_3; stw 3,0x94(31); cmpwi 3,0; beq 7f; lwz 0,0x14(3); cmpwi 0,0; bne 1f; lwz 3,0x18(3); li 0,0; cmpwi 3,0; beq 1f; lwz 0,0x14(3); 1:; cmpwi 0,0; beq 7f; lwz 9,0x94(31); lwz 3,0x14(9); cmpwi 3,0; bne 2f; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 2f; lwz 3,0x14(9); 2:; li 4,0; bl _s80110D44_4; cmpwi 3,0; beq 7f; lwz 9,0x94(31); lwz 3,0x14(9); cmpwi 3,0; bne 3f; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 3f; lwz 3,0x14(9); 3:; li 4,0; bl _s80110D44_5; b 7f; 4:; lwz 30,-32056(13); mr 3,31; bl _s80110D44_6; mr 4,3; mr 3,30; bl _s80110D44_7; mr. 5,3; li 3,0; beq 5f; lwz 3,-32056(13); lis 4,29800; extsh 5,5; ori 4,4,28002; lwz 9,0xc(3); li 6,0; lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; 5:; cmpwi 3,0; beq 6f; lis 5,29800; mr 4,3; stw 31,0x8(1); addi 3,1,8; ori 5,5,28002; li 6,0; bl _s80110D44_8; b 7f; 6:; lwz 3,-21432(13); mr 4,31; bl _s80110D44_9; 7:; lwz 0,0x94(31); stw 0,0x0(29); cmpwi 0,0; li 3,0; beq 8f; lwz 3,0x94(31); bl _s80110D44_10; li 3,1; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80110D44_0();
extern "C" void _s80110D44_1();
extern "C" void _s80110D44_2();
extern "C" void _s80110D44_3();
extern "C" void _s80110D44_4();
extern "C" void _s80110D44_5();
extern "C" void _s80110D44_6();
extern "C" void _s80110D44_7();
extern "C" void _s80110D44_8();
extern "C" void _s80110D44_9();
extern "C" void _s80110D44_10();
extern "C" void f_80110D44() {}
