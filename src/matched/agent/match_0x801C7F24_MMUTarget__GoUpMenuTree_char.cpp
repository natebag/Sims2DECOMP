// 0x801C7F24 MMUTarget::GoUpMenuTree(char (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 29,0x11c(1); stw 0,0x12c(1); mr 29,3; addi 11,29,216; addi 3,29,200; lwz 9,0xc(11); lwz 10,0xc(3); lwz 8,0x4(11); subf 9,10,9; lwz 0,0xd8(29); srawi 9,9,2; lwz 11,0x8(3); lwz 10,0xc8(29); subf 0,8,0; addi 9,9,-1; srawi 0,0,2; subf 11,10,11; rlwinm 9,9,5,0,26; add 9,9,0; srawi 11,11,2; add 9,9,11; cmpwi 9,1; beq 4f; li 0,0; stw 0,0xf8(29); lwz 9,0x10(3); lwz 0,0x14(3); cmpw 9,0; beq 0f; addi 0,9,-4; stw 0,0x10(3); b 1f; 0:; bl _s801C7F24_0; 1:; addi 9,29,216; lwz 10,0xd8(29); lwz 11,0x4(9); addi 7,1,8; lwz 8,0xc(9); lwz 0,0x8(9); cmpw 10,11; stw 10,0x8(1); stw 0,0x10(1); stw 11,0xc(1); stw 8,0x14(1); bne 2f; addi 0,8,-4; stw 0,0x14(1); lwz 9,-4(8); addi 11,9,128; stw 9,0xc(1); stw 11,0x10(1); lwz 0,0x8(7); stw 0,0x8(1); 2:; lwz 9,0x8(1); addi 0,9,-4; stw 0,0x8(1); lwz 31,-4(9); cmpwi 31,0; bne 3f; lwz 3,-26524(13); li 4,0; bl _s801C7F24_1; lwz 3,-26524(13); li 4,1; bl _s801C7F24_2; lis 9,-32697; lwz 3,-25136(13); addi 9,9,24012; li 4,1; lwz 11,0xb4(9); stw 31,0x3ac(11); lwz 10,0xb4(9); stw 31,0x3a8(10); bl _s801C7F24_3; lwz 3,-21492(13); cmpwi 3,0; beq 3f; lwz 0,0xc(3); cmpwi 0,0; beq 3f; bl _s801C7F24_4; 3:; addi 30,1,24; lis 4,-32705; addi 4,4,-8800; mr 5,31; mr 3,30; crxor 6,6,6; bl _s801C7F24_5; lwz 9,0x80(29); lis 4,-32705; addi 4,4,9936; mr 5,30; lha 3,0x10(9); lwz 0,0x14(9); add 3,29,3; mtspr 8,0; blrl; 4:; lwz 0,0x12c(1); mtspr 8,0; lmw 29,0x11c(1); addi 1,1,296"
extern "C" void _s801C7F24_0();
extern "C" void _s801C7F24_1();
extern "C" void _s801C7F24_2();
extern "C" void _s801C7F24_3();
extern "C" void _s801C7F24_4();
extern "C" void _s801C7F24_5();
extern "C" void f_801C7F24() {}
