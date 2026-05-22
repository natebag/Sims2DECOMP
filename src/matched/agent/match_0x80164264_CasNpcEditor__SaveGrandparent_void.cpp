// 0x80164264 CasNpcEditor::SaveGrandparent(void) (868 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; mfcr 12; stmw 21,0x5c(1); stw 0,0x8c(1); stw 12,0x58(1); mr 26,3; lwz 23,0x8(26); cmpwi 23,2; bne 0f; lwz 0,0x10(26); cmplwi 0,51; ble 1f; 0:; li 3,0; b 12f; 1:; lwz 3,0x0(26); bl _s80164264_0; mr. 27,3; beq 10f; lwz 0,0x10(26); mr 31,0; subfic 24,31,25; li 24,0; adde. 24,24,24; bne 2f; addi 31,31,-26; 2:; addi 3,1,8; li 29,0; mr 21,3; bl _s80164264_1; addi 3,1,16; bl _s80164264_2; stw 29,0x118(27); addi 4,27,4; li 5,32; addi 3,26,24; bl _s80164264_3; addi 4,27,68; li 5,32; addi 3,26,56; bl _s80164264_4; lwz 3,0x58(26); mr 4,24; mr 5,31; mr 6,27; bl _s80164264_5; lwz 9,0x0(26); mr. 25,3; mcrf cr4,cr0; lwz 28,0x14(9); cmpwi 28,0; beq 7f; addi 30,1,24; mr 5,31; mr 4,24; mr 3,30; bl _s80164264_6; lwz 4,0x18(1); addi 24,1,16; mr 3,21; bl _s80164264_7; lwz 4,0x18(1); mr 3,30; bl _s80164264_8; lwz 5,0x5c(26); lis 4,-32706; lwz 6,0x8(1); addi 4,4,-2260; mr 3,24; crxor 6,6,6; bl _s80164264_9; mr 3,24; bl _s80164264_10; lwz 3,0x10(1); lis 4,-32706; addi 4,4,-2248; bl _s80164264_11; mr. 30,3; beq 3f; mr 3,27; mr 4,30; addi 5,28,8; bl _s80164264_12; mr 3,30; bl _s80164264_13; 3:; mr 3,28; li 4,64; li 5,64; li 6,32; li 7,0; li 8,0; bl _s80164264_14; mr. 31,3; beq 8f; addi 28,1,32; addi 30,1,72; addi 27,1,64; mr 3,28; bl _s80164264_15; mr 22,30; stb 29,0x24(1); addi 9,1,36; li 11,0; li 10,32; li 0,8; stb 23,0x2(9); stb 0,0x13(9); addi 3,1,72; stb 11,0x8(9); li 25,0; stb 10,0x12(9); stb 29,0x1(9); sth 29,0x4(9); sth 29,0x6(9); sth 29,0xa(9); sth 29,0xc(9); sth 29,0xe(9); sth 29,0x10(9); stw 29,0x18(28); stw 29,0x1c(28); stw 29,0x40(1); stw 29,0x4(27); bl _s80164264_16; addi 3,1,76; bl _s80164264_17; addi 3,1,80; bl _s80164264_18; lis 4,-32706; mr 3,30; addi 4,4,-2228; bl _s80164264_19; lwz 5,0x60(26); lis 4,-32706; lwz 6,0x8(1); mr 3,24; addi 4,4,-2188; crxor 6,6,6; bl _s80164264_20; mr 3,24; bl _s80164264_21; beq cr4,4f; lwz 4,0x10(1); mr 3,28; mr 8,27; mr 5,31; li 6,1; li 7,0; bl _s80164264_22; cmpwi 3,0; beq 4f; li 25,1; 4:; cmpwi 31,0; beq 6f; lwz 3,-26392(13); mr 4,31; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 5f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 5:; lwz 3,-26392(13); mr 4,31; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; 6:; lwz 4,0x50(1); addi 3,1,80; bl _s80164264_23; lwz 4,0x4c(1); addi 3,1,76; bl _s80164264_24; lwz 4,0x48(1); mr 3,22; bl _s80164264_25; lwz 4,0x20(1); addi 3,1,32; bl _s80164264_26; b 8f; 7:; li 25,0; 8:; cmpwi 25,0; li 31,0; beq 9f; lwz 3,0x58(26); bl _s80164264_27; cmpwi 3,0; beq 9f; li 31,1; 9:; lwz 4,0x10(1); addi 3,1,16; mr 25,31; bl _s80164264_28; lwz 4,0x8(1); mr 3,21; bl _s80164264_29; b 11f; 10:; li 25,0; 11:; mr 3,25; 12:; lwz 0,0x8c(1); lwz 12,0x58(1); mtspr 8,0; lmw 21,0x5c(1); mtcrf 8,12; addi 1,1,136"
extern "C" void _s80164264_0();
extern "C" void _s80164264_1();
extern "C" void _s80164264_2();
extern "C" void _s80164264_3();
extern "C" void _s80164264_4();
extern "C" void _s80164264_5();
extern "C" void _s80164264_6();
extern "C" void _s80164264_7();
extern "C" void _s80164264_8();
extern "C" void _s80164264_9();
extern "C" void _s80164264_10();
extern "C" void _s80164264_11();
extern "C" void _s80164264_12();
extern "C" void _s80164264_13();
extern "C" void _s80164264_14();
extern "C" void _s80164264_15();
extern "C" void _s80164264_16();
extern "C" void _s80164264_17();
extern "C" void _s80164264_18();
extern "C" void _s80164264_19();
extern "C" void _s80164264_20();
extern "C" void _s80164264_21();
extern "C" void _s80164264_22();
extern "C" void _s80164264_23();
extern "C" void _s80164264_24();
extern "C" void _s80164264_25();
extern "C" void _s80164264_26();
extern "C" void _s80164264_27();
extern "C" void _s80164264_28();
extern "C" void _s80164264_29();
extern "C" void f_80164264() {}
