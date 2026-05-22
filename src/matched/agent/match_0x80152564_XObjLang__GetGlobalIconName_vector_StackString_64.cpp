// 0x80152564 XObjLang::GetGlobalIconName(vector<StackString<64>, (656 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 21,0x5c(1); stw 0,0x8c(1); mr 28,3; lwz 11,0x0(28); lwz 0,0x4(28); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,72; cmpw 9,0; bne 0b; 1:; stw 11,0x4(28); lis 9,-32697; lis 4,-32706; lwz 3,0x5eb4(9); addi 4,4,-8532; bl _s80152564_0; mr. 22,3; beq 19f; lis 23,14563; li 25,0; ori 23,23,36409; lis 21,-32706; b 17f; 2:; addi 29,1,8; li 5,64; addi 4,29,8; mr 3,29; bl _s80152564_1; rlwinm 30,25,3,0,28; mr 3,29; addi 4,21,-8516; li 5,-1; bl _s80152564_2; lwzx 4,31,30; mr 3,29; bl _s80152564_3; lwz 31,0x4(28); lwz 0,0xc(28); cmpw 31,0; beq 3f; addi 4,31,8; li 5,64; mr 3,31; addi 25,25,1; bl _s80152564_4; mr 3,31; mr 4,29; li 5,-1; bl _s80152564_5; lwz 9,0x4(28); addi 9,9,72; stw 9,0x4(28); b 17f; 3:; lwz 0,0x0(28); mr 27,31; li 9,1; addi 10,1,84; subf 0,0,27; stw 9,0x54(1); mullw 0,0,23; addi 11,1,80; srawi 9,0,3; stw 9,0x50(1); cmplwi 9,1; bge 4f; mr 11,10; 4:; lwz 0,0x0(11); add. 3,9,0; beq 6f; mulli 3,3,72; cmplwi 3,128; mr 24,3; ble 5f; bl _s80152564_6; b 7f; 5:; bl _s80152564_7; b 7f; 6:; li 3,0; li 24,0; 7:; mr 31,3; lwz 30,0x0(28); mr 26,31; addi 25,25,1; cmpw 30,27; beq 9f; 8:; addi 4,31,8; mr 3,31; li 5,64; bl _s80152564_8; mr 3,31; mr 4,30; li 5,-1; addi 30,30,72; bl _s80152564_9; addi 31,31,72; cmpw 30,27; bne 8b; 9:; lwz 0,0x54(1); cmpwi 0,1; bne 10f; addi 4,31,8; mr 3,31; li 5,64; bl _s80152564_10; mr 3,31; mr 4,29; li 5,-1; addi 31,31,72; bl _s80152564_11; b 12f; 10:; mr. 30,0; beq 12f; 11:; addi 4,31,8; mr 3,31; li 5,64; bl _s80152564_12; mr 3,31; mr 4,29; li 5,-1; addi 31,31,72; bl _s80152564_13; addic. 30,30,-1; bne 11b; 12:; lwz 9,0x0(28); lwz 11,0x4(28); mr 3,9; lwz 0,0xc(28); cmpw 9,11; beq 14f; 13:; addi 9,9,72; cmpw 9,11; bne 13b; 14:; subf 0,3,0; cmpwi 3,0; mullw 0,0,23; srawi 0,0,3; beq 16f; mulli 4,0,72; cmplwi 4,128; ble 15f; bl _s80152564_14; b 16f; 15:; bl _s80152564_15; 16:; add 0,24,26; stw 26,0x0(28); stw 31,0x4(28); stw 0,0xc(28); 17:; lwz 9,0x4(22); li 0,0; lwz 31,0x0(9); cmpwi 31,0; beq 18f; lwz 0,-4(31); 18:; cmpw 25,0; blt 2b; 19:; li 3,1; lwz 0,0x8c(1); mtspr 8,0; lmw 21,0x5c(1); addi 1,1,136"
extern "C" void _s80152564_0();
extern "C" void _s80152564_1();
extern "C" void _s80152564_2();
extern "C" void _s80152564_3();
extern "C" void _s80152564_4();
extern "C" void _s80152564_5();
extern "C" void _s80152564_6();
extern "C" void _s80152564_7();
extern "C" void _s80152564_8();
extern "C" void _s80152564_9();
extern "C" void _s80152564_10();
extern "C" void _s80152564_11();
extern "C" void _s80152564_12();
extern "C" void _s80152564_13();
extern "C" void _s80152564_14();
extern "C" void _s80152564_15();
extern "C" void f_80152564() {}
