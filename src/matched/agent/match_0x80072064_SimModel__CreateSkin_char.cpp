// 0x80072064 SimModel::CreateSkin(char (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 20,0x38(1); stw 0,0x6c(1); mr 29,3; mr 25,4; addi 22,1,40; bl _s80072064_0; mr 20,22; li 0,0; addi 9,1,8; stw 0,0x8(1); li 8,64; li 11,1; li 10,32; lwz 4,0x150(29); mr 3,9; sth 8,0x10(9); li 26,0; stb 11,0x18(9); lis 23,-32692; stb 10,0x1a(9); addi 21,1,48; stw 0,0x1c(9); stw 0,0x4(9); stw 0,0x8(9); sth 8,0x12(9); stb 0,0x19(9); stb 0,0x1b(9); sth 0,0x14(9); sth 0,0x16(9); bl _s80072064_1; 0:; lwz 3,0x13c(29); mr 4,25; mr 5,26; rlwinm 30,26,2,0,29; bl _s80072064_2; mr 27,30; mr 28,3; lwz 4,0x13c(29); mr 5,25; mr 6,26; mr 3,20; bl _s80072064_3; lwz 4,0x28(1); add 30,30,29; addi 3,30,344; bl _s80072064_4; lwz 4,0x28(1); mr 3,20; bl _s80072064_5; addi 3,23,-7364; mr 4,28; bl _s80072064_6; cmpwi 3,0; beq 6f; mr 3,22; mr 4,25; bl _s80072064_7; li 30,2; li 31,0; lis 24,-32707; 1:; cmplwi 30,99; ble 2f; cmpwi 31,0; bne 4f; addi 3,23,-7364; li 31,1; bl _s80072064_8; li 30,2; 2:; mr 6,30; mr 3,22; addi 4,24,22004; mr 5,25; crxor 6,6,6; bl _s80072064_9; addi 30,30,1; lwz 4,0x28(1); mr 5,26; lwz 3,0x13c(29); bl _s80072064_10; mr 28,3; addi 3,23,-7364; mr 4,28; bl _s80072064_11; cmpwi 3,0; bne 1b; 3:; cmplwi 31,1; ble 5f; lwz 4,0x28(1); addi 3,1,40; bl _s80072064_12; b 9f; 4:; addi 31,31,1; b 3b; 5:; lwz 5,0x28(1); mr 6,26; lwz 4,0x13c(29); mr 3,21; bl _s80072064_13; lwz 4,0x30(1); add 3,27,29; addi 3,3,344; bl _s80072064_14; lwz 4,0x30(1); mr 3,21; bl _s80072064_15; lwz 4,0x28(1); addi 3,1,40; bl _s80072064_16; 6:; add 9,27,29; lwz 11,-26392(13); lwz 0,0x158(9); addi 4,1,8; stw 0,0x24(1); lwz 9,0x0(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; mr. 30,3; beq 9f; li 4,24; li 5,8; addi 3,23,-7364; addi 31,29,320; bl _s80072064_17; bl _s80072064_18; stwx 3,31,27; cmpwi 3,0; bne 8f; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 7f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 7:; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; b 9f; 8:; mr 4,30; bl _s80072064_19; lhz 0,0x1a(1); mr 5,28; lhz 11,0x18(1); addi 3,23,-7364; lbz 8,0x22(1); mullw 11,11,0; lbz 9,0x23(1); lhz 10,0x1c(1); rlwinm 8,8,29,3,31; rlwinm 9,9,29,3,31; lwzx 7,31,27; mullw 10,10,9; lwz 0,0x10(7); mullw 11,11,8; add 11,11,10; rlwimi 0,11,8,0,23; stw 0,0x10(7); lwzx 4,31,27; bl _s80072064_20; addi 0,26,1; rlwinm 26,0,0,24,31; cmplwi 26,3; ble 0b; 9:; lwz 0,0x6c(1); mtspr 8,0; lmw 20,0x38(1); addi 1,1,104"
extern "C" void _s80072064_0();
extern "C" void _s80072064_1();
extern "C" void _s80072064_2();
extern "C" void _s80072064_3();
extern "C" void _s80072064_4();
extern "C" void _s80072064_5();
extern "C" void _s80072064_6();
extern "C" void _s80072064_7();
extern "C" void _s80072064_8();
extern "C" void _s80072064_9();
extern "C" void _s80072064_10();
extern "C" void _s80072064_11();
extern "C" void _s80072064_12();
extern "C" void _s80072064_13();
extern "C" void _s80072064_14();
extern "C" void _s80072064_15();
extern "C" void _s80072064_16();
extern "C" void _s80072064_17();
extern "C" void _s80072064_18();
extern "C" void _s80072064_19();
extern "C" void _s80072064_20();
extern "C" void f_80072064() {}
