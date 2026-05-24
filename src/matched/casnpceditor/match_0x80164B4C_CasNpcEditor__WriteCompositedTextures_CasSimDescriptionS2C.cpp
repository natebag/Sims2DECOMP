// 0x80164B4C CasNpcEditor::WriteCompositedTextures(CasSimDescriptionS2C (672 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; stmw 18,0x80(1); stw 0,0xbc(1); mr 23,3; mr. 24,4; bne 0f; li 3,0; b 6f; 0:; li 30,0; addi 9,1,8; stw 30,0x8(1); li 11,64; li 0,1; li 26,32; addi 28,1,80; mr 3,9; sth 11,0x10(9); addi 27,1,40; stb 0,0x18(9); li 4,1; sth 11,0x12(9); addi 25,1,112; stw 30,0x4(9); li 29,0; stw 30,0x8(9); mr 20,27; stb 30,0x19(9); mr 18,28; stb 26,0x1a(9); li 22,1; stb 30,0x1b(9); li 31,0; sth 30,0x14(9); lis 19,-32692; sth 30,0x16(9); stw 30,0x1c(9); bl _s80164B4C_0; addi 21,1,120; mr 3,27; bl _s80164B4C_1; mr 3,28; bl _s80164B4C_2; stb 29,0x54(1); addi 9,1,84; li 11,2; li 0,8; stb 0,0x13(9); stb 11,0x2(9); stb 29,0x8(9); stb 26,0x12(9); stb 29,0x1(9); sth 30,0x4(9); sth 30,0x6(9); sth 30,0xa(9); sth 30,0xc(9); sth 30,0xe(9); sth 30,0x10(9); stw 30,0x1c(28); stw 30,0x18(28); 1:; mr 6,31; mr 4,23; mr 5,24; mr 3,25; bl _s80164B4C_3; addi 3,1,120; bl _s80164B4C_4; li 4,24; li 5,8; addi 3,19,-7364; bl _s80164B4C_5; bl _s80164B4C_6; mr 30,3; addi 4,1,8; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 3f; cmpwi 30,0; beq 2f; lwz 9,0x0(30); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; 2:; lwz 4,0x78(1); addi 3,1,120; bl _s80164B4C_7; lwz 4,0x70(1); mr 3,25; bl _s80164B4C_8; b 5f; 3:; mr 4,3; li 29,0; mr 3,30; bl _s80164B4C_9; lhz 11,0x1a(1); mr 4,30; lhz 9,0x18(1); mr 3,20; lbz 8,0x22(1); mr 5,31; mullw 9,9,11; lbz 0,0x23(1); lhz 10,0x1c(1); rlwinm 8,8,29,3,31; rlwinm 0,0,29,3,31; lwz 11,0x10(30); mullw 10,10,0; mr 6,24; mullw 9,9,8; add 9,9,10; rlwimi 11,9,8,0,23; stw 11,0x10(30); bl _s80164B4C_10; lwz 5,0x64(23); lis 4,-32706; lwz 6,0x70(1); addi 4,4,-2188; mr 3,21; crxor 6,6,6; bl _s80164B4C_11; mr 3,21; bl _s80164B4C_12; cmpwi 22,0; beq 4f; lwz 4,0x78(1); mr 3,18; lwz 5,0x14(30); li 6,1; li 7,0; li 8,0; bl _s80164B4C_13; cmpwi 3,0; beq 4f; li 29,1; 4:; mr 3,30; mr 22,29; bl _s80164B4C_14; lwz 4,0x78(1); addi 3,1,120; bl _s80164B4C_15; lwz 4,0x70(1); addi 3,1,112; bl _s80164B4C_16; 5:; addi 0,31,1; rlwinm 31,0,0,24,31; cmplwi 31,3; ble 1b; lwz 4,0x50(1); addi 3,1,80; bl _s80164B4C_17; mr 3,20; li 4,2; bl _s80164B4C_18; mr 3,22; 6:; lwz 0,0xbc(1); mtspr 8,0; lmw 18,0x80(1); addi 1,1,184"

extern "C" void _s80164B4C_0();
extern "C" void _s80164B4C_1();
extern "C" void _s80164B4C_2();
extern "C" void _s80164B4C_3();
extern "C" void _s80164B4C_4();
extern "C" void _s80164B4C_5();
extern "C" void _s80164B4C_6();
extern "C" void _s80164B4C_7();
extern "C" void _s80164B4C_8();
extern "C" void _s80164B4C_9();
extern "C" void _s80164B4C_10();
extern "C" void _s80164B4C_11();
extern "C" void _s80164B4C_12();
extern "C" void _s80164B4C_13();
extern "C" void _s80164B4C_14();
extern "C" void _s80164B4C_15();
extern "C" void _s80164B4C_16();
extern "C" void _s80164B4C_17();
extern "C" void _s80164B4C_18();

struct CasNpcEditor {
    void WriteCompositedTextures_CasSimDescriptionS2C();
};

void CasNpcEditor::WriteCompositedTextures_CasSimDescriptionS2C() {
}
