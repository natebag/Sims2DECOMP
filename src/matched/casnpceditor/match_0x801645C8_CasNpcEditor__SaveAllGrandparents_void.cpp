// 0x801645C8 CasNpcEditor::SaveAllGrandparents(void) (1268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-456(1); mfspr 0,8; mfcr 12; stmw 14,0x180(1); stw 0,0x1cc(1); stw 12,0x17c(1); mr 25,3; addi 30,1,8; lwz 9,0x0(25); mr 3,30; li 23,1; lwz 9,0x14(9); stw 9,0x170(1); bl _s801645C8_0; li 10,0; addi 9,1,12; stb 10,0xc(1); li 0,0; stb 10,0x1(9); li 8,2; li 7,32; li 11,8; stb 11,0x13(9); li 10,0; stb 8,0x2(9); addi 3,1,40; sth 0,0x10(9); stb 7,0x12(9); sth 0,0x4(9); sth 0,0x6(9); stb 0,0x8(9); sth 0,0xa(9); sth 0,0xc(9); sth 0,0xe(9); stw 10,0x1c(30); stw 10,0x18(30); bl _s801645C8_1; lwz 9,0x170(1); cmpwi 9,0; bne 0f; lwz 4,0x28(1); addi 3,1,40; bl _s801645C8_2; lwz 4,0x8(1); addi 3,1,8; bl _s801645C8_3; li 3,0; b 13f; 0:; li 31,0; addi 28,1,68; 1:; subfic 20,31,25; li 20,0; adde. 20,20,20; mr 26,31; mfcr 30; bne 2f; addi 26,31,-26; 2:; mr 3,25; mr 4,31; bl _s801645C8_4; addi 0,31,1; mr. 27,3; stw 0,0x174(1); beq 11f; addi 3,1,48; rlwinm 30,30,16,0,31; mtcrf 8,30; rlwinm 30,30,16,0,31; bl _s801645C8_5; lis 18,-32698; addi 3,1,56; addi 29,1,64; bl _s801645C8_6; addi 23,25,24; li 0,0; lis 9,-32698; stw 0,0x118(27); addi 9,9,24616; addi 3,1,72; lis 17,-32706; lwz 30,0x0(25); addi 24,25,56; stw 9,0x44(1); lis 16,-32706; bl _s801645C8_7; addi 22,27,4; li 0,0; addi 11,1,72; stw 0,0x40(1); mr 9,27; li 10,288; addi 21,27,68; addi 19,1,56; lis 15,-32706; lis 14,-32706; 3:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 3b; lwz 0,0x0(9); mr 3,30; mr 4,29; stw 0,0x0(11); bl _s801645C8_8; addi 0,18,24616; mr 3,29; stw 0,0x44(1); li 4,2; bl _s801645C8_9; stw 31,0x10(25); beq cr4,4f; lis 9,-32706; addi 6,9,-2160; b 5f; 4:; lis 9,-32706; addi 6,9,-2152; 5:; addi 5,17,-2164; li 4,32; mr 3,23; li 31,0; crxor 6,6,6; bl _s801645C8_10; mr 6,26; addi 5,16,-2144; li 4,32; mr 3,24; crxor 6,6,6; bl _s801645C8_11; mr 4,22; mr 3,23; li 5,32; bl _s801645C8_12; mr 4,21; li 5,32; mr 3,24; bl _s801645C8_13; stw 31,0xc(25); mr 6,27; lwz 3,0x58(25); mr 4,20; mr 5,26; bl _s801645C8_14; mr. 23,3; mr 5,26; mcrf cr4,cr0; mr 4,20; mr 3,29; bl _s801645C8_15; lwz 4,0x40(1); addi 3,1,48; bl _s801645C8_16; lwz 4,0x40(1); mr 3,29; bl _s801645C8_17; lwz 5,0x5c(25); addi 4,15,-2260; lwz 6,0x30(1); mr 3,19; crxor 6,6,6; bl _s801645C8_18; mr 3,19; bl _s801645C8_19; lwz 3,0x38(1); addi 4,14,-2248; bl _s801645C8_20; mr. 30,3; beq 6f; lwz 9,0x170(1); mr 3,27; mr 4,30; addi 5,9,8; bl _s801645C8_21; mr 3,30; bl _s801645C8_22; 6:; lwz 3,0x170(1); li 4,64; li 5,64; li 6,32; li 7,0; li 8,0; bl _s801645C8_23; mr. 30,3; beq 10f; addi 27,1,96; mr 3,29; bl _s801645C8_24; li 26,0; stb 31,0x44(1); li 0,2; stb 0,0x2(28); li 9,32; li 11,8; li 0,0; stb 9,0x12(28); addi 3,1,104; stb 11,0x13(28); mr 24,3; stb 0,0x8(28); stb 31,0x1(28); sth 31,0x4(28); sth 31,0x6(28); sth 31,0xa(28); sth 31,0xc(28); sth 31,0xe(28); sth 31,0x10(28); stw 31,0x18(29); stw 31,0x1c(29); stw 31,0x60(1); stw 31,0x4(27); bl _s801645C8_25; addi 3,1,108; bl _s801645C8_26; addi 3,1,112; bl _s801645C8_27; lis 4,-32706; addi 3,1,104; addi 4,4,-2228; bl _s801645C8_28; lwz 5,0x60(25); lis 4,-32706; lwz 6,0x30(1); mr 3,19; addi 4,4,-2188; crxor 6,6,6; bl _s801645C8_29; mr 3,19; bl _s801645C8_30; beq cr4,7f; lwz 4,0x38(1); mr 3,29; mr 8,27; mr 5,30; li 6,1; li 7,0; bl _s801645C8_31; cmpwi 3,0; beq 7f; li 26,1; 7:; mr 23,26; cmpwi 30,0; beq 9f; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 8f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 8:; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; 9:; lwz 4,0x70(1); addi 3,1,112; bl _s801645C8_32; lwz 4,0x6c(1); addi 3,1,108; bl _s801645C8_33; lwz 4,0x68(1); mr 3,24; bl _s801645C8_34; lwz 4,0x40(1); addi 3,1,64; bl _s801645C8_35; 10:; lwz 4,0x38(1); addi 3,1,56; bl _s801645C8_36; lwz 4,0x30(1); addi 3,1,48; bl _s801645C8_37; 11:; lwz 31,0x174(1); cmplwi 31,51; ble 1b; cmpwi 23,0; beq 12f; lwz 3,0x58(25); bl _s801645C8_38; 12:; lwz 4,0x28(1); addi 3,1,40; bl _s801645C8_39; lwz 4,0x8(1); addi 3,1,8; bl _s801645C8_40; li 3,1; 13:; lwz 0,0x1cc(1); lwz 12,0x17c(1); mtspr 8,0; lmw 14,0x180(1); mtcrf 8,12; addi 1,1,456"

extern "C" void _s801645C8_0();
extern "C" void _s801645C8_1();
extern "C" void _s801645C8_2();
extern "C" void _s801645C8_3();
extern "C" void _s801645C8_4();
extern "C" void _s801645C8_5();
extern "C" void _s801645C8_6();
extern "C" void _s801645C8_7();
extern "C" void _s801645C8_8();
extern "C" void _s801645C8_9();
extern "C" void _s801645C8_10();
extern "C" void _s801645C8_11();
extern "C" void _s801645C8_12();
extern "C" void _s801645C8_13();
extern "C" void _s801645C8_14();
extern "C" void _s801645C8_15();
extern "C" void _s801645C8_16();
extern "C" void _s801645C8_17();
extern "C" void _s801645C8_18();
extern "C" void _s801645C8_19();
extern "C" void _s801645C8_20();
extern "C" void _s801645C8_21();
extern "C" void _s801645C8_22();
extern "C" void _s801645C8_23();
extern "C" void _s801645C8_24();
extern "C" void _s801645C8_25();
extern "C" void _s801645C8_26();
extern "C" void _s801645C8_27();
extern "C" void _s801645C8_28();
extern "C" void _s801645C8_29();
extern "C" void _s801645C8_30();
extern "C" void _s801645C8_31();
extern "C" void _s801645C8_32();
extern "C" void _s801645C8_33();
extern "C" void _s801645C8_34();
extern "C" void _s801645C8_35();
extern "C" void _s801645C8_36();
extern "C" void _s801645C8_37();
extern "C" void _s801645C8_38();
extern "C" void _s801645C8_39();
extern "C" void _s801645C8_40();

struct CasNpcEditor {
    void SaveAllGrandparents();
};

void CasNpcEditor::SaveAllGrandparents() {
}
