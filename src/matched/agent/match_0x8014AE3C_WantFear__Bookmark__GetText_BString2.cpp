// 0x8014AE3C WantFear::Bookmark::GetText(BString2 (1328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-240(1); mfspr 0,8; mfcr 12; stmw 23,0xcc(1); stw 0,0xf4(1); stw 12,0xc8(1); mr 24,3; mr 30,4; mr 23,5; mr 28,6; li 31,0; bl _s8014AE3C_0; mr 27,3; lwz 3,0x4(24); bl _s8014AE3C_1; lwz 9,0x4(24); mr 29,3; lbz 0,0x4(9); cmpwi 0,0; beq 2f; lbz 0,0x1d(9); andi. 9,0,2; beq 0f; mr 3,24; bl _s8014AE3C_2; cmpwi 3,0; beq 2f; 0:; lwz 11,0x4(24); cmpwi 28,0; lbz 9,0x4(11); addi 9,9,1; extsb 31,9; beq 1f; addi 0,31,1; extsb 31,0; 1:; mr 4,31; mr 3,29; mr 5,30; bl _s8014AE3C_3; mr 31,3; 2:; cmpwi 31,0; cmpwi 4,28,0; bne 5f; cmpwi 27,0; li 31,1; beq 3f; lbz 0,0xa(29); li 31,3; cmpwi 0,4; bne 3f; lwz 3,-21476(13); mr 4,27; lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 3f; lwz 9,0xc(3); lwz 11,0x8c(9); lwz 0,0x84(11); cmpwi 0,0; bne 3f; li 31,5; 3:; cmpwi 4,28,0; beq cr4,4f; addi 0,31,1; extsb 31,0; 4:; mr 4,31; mr 3,29; mr 5,30; bl _s8014AE3C_4; 5:; lbz 0,0xa(29); li 28,0; li 25,0; extsb 5,0; cmpwi 5,4; bne 8f; lwz 10,-21476(13); mr 4,27; lis 9,-32706; lwz 11,0x0(10); addi 28,9,-8952; lha 3,0xb8(11); lwz 0,0xbc(11); add 3,10,3; mtspr 8,0; blrl; mr. 3,3; beq 6f; lwz 3,0xc(3); bl _s8014AE3C_5; bl _s8014AE3C_6; mr 4,3; addi 3,1,8; bl _s8014AE3C_7; b 7f; 6:; lis 4,-32706; addi 3,1,8; addi 4,4,-8940; bl _s8014AE3C_8; 7:; addi 25,1,8; b 19f; 8:; cmpwi 5,0; beq 19f; cmpwi 5,3; beq 13f; bgt 9f; cmpwi 5,1; beq 11f; cmpwi 5,2; beq 12f; b 17f; 9:; cmpwi 5,6; beq 15f; bgt 10f; cmpwi 5,5; beq 14f; b 17f; 10:; cmpwi 5,7; beq 16f; b 17f; 11:; lis 9,-32706; addi 28,9,-8920; b 17f; 12:; lis 9,-32706; addi 28,9,-8900; b 17f; 13:; lis 9,-32706; addi 28,9,-8884; b 17f; 14:; lis 9,-32706; addi 28,9,-8868; b 17f; 15:; lis 9,-32706; addi 28,9,-8840; b 17f; 16:; lis 9,-32706; addi 28,9,-8824; 17:; lis 4,-32697; mr 6,27; addi 4,4,24012; addi 3,1,192; crxor 6,6,6; bl _s8014AE3C_9; lwz 9,0xc0(1); li 6,0; cmpwi 9,0; beq 18f; lwz 6,0x0(9); 18:; mr 25,6; 19:; cmpwi 28,0; addi 29,1,136; addi 27,1,144; addi 26,1,160; beq 22f; b 21f; 20:; mr 3,28; bl _s8014AE3C_10; mr 5,3; mr 4,31; mr 6,25; mr 3,30; bl _s8014AE3C_11; 21:; mr 3,30; mr 4,28; li 5,0; bl _s8014AE3C_12; mr 31,3; cmpwi 31,-1; bne 20b; 22:; mr 3,29; bl _s8014AE3C_13; lwz 9,0x4(24); lis 4,-32706; addi 4,4,-8800; mr 3,27; lha 5,0x8(9); crxor 6,6,6; bl _s8014AE3C_14; mr 4,27; mr 3,29; bl _s8014AE3C_15; lis 9,-32706; mr 3,30; addi 28,9,-8796; li 5,0; mr 4,28; b 24f; 23:; mr 4,3; li 5,4; mr 6,29; li 7,0; li 8,-1; mr 3,30; bl _s8014AE3C_16; mr 3,30; mr 4,28; li 5,0; 24:; bl _s8014AE3C_17; cmpwi 3,-1; bne 23b; li 4,2; mr 3,29; bl _s8014AE3C_18; mr 3,29; bl _s8014AE3C_19; lwz 9,0x4(24); li 5,1; mr 4,26; lha 3,0x8(9); mulli 3,3,100; bl _s8014AE3C_20; mr 4,26; mr 3,29; bl _s8014AE3C_21; lis 9,-32706; mr 3,30; addi 28,9,-8784; li 5,0; mr 4,28; b 26f; 25:; mr 4,3; li 5,14; mr 6,29; li 7,0; li 8,-1; mr 3,30; bl _s8014AE3C_22; mr 3,30; mr 4,28; li 5,0; 26:; bl _s8014AE3C_23; cmpwi 3,-1; bne 25b; li 4,2; mr 3,29; bl _s8014AE3C_24; mr 3,29; bl _s8014AE3C_25; lwz 9,0x4(24); li 5,1; mr 4,27; lha 3,0x8(9); bl _s8014AE3C_26; mr 4,27; mr 3,29; bl _s8014AE3C_27; lis 9,-32706; mr 3,30; addi 28,9,-8752; li 5,0; mr 4,28; b 28f; 27:; mr 4,3; li 5,6; mr 6,29; li 7,0; li 8,-1; mr 3,30; bl _s8014AE3C_28; mr 3,30; mr 4,28; li 5,0; 28:; bl _s8014AE3C_29; cmpwi 3,-1; bne 27b; mr 3,29; li 4,2; bl _s8014AE3C_30; lis 9,-32706; mr 3,30; addi 28,9,-8736; li 5,0; mr 4,28; b 30f; 29:; lwz 3,0xc(23); bl _s8014AE3C_31; mr 6,3; mr 4,31; li 5,3; li 7,0; li 8,-1; mr 3,30; bl _s8014AE3C_32; mr 3,30; mr 4,28; li 5,0; 30:; bl _s8014AE3C_33; mr 31,3; cmpwi 31,-1; bne 29b; bne cr4,31f; mr 3,29; bl _s8014AE3C_34; lwz 9,0x4(24); lis 4,-32706; addi 4,4,-8728; mr 3,27; lha 5,0xe(9); crxor 6,6,6; bl _s8014AE3C_35; mr 4,27; mr 3,29; bl _s8014AE3C_36; lis 4,-32706; mr 3,30; addi 4,4,-8724; bl _s8014AE3C_37; mr 4,29; li 5,0; li 6,-1; mr 3,30; bl _s8014AE3C_38; lis 4,-32706; mr 3,30; addi 4,4,-8716; bl _s8014AE3C_39; mr 3,29; li 4,2; bl _s8014AE3C_40; 31:; mr 3,30; bl _s8014AE3C_41; lwz 0,0xf4(1); lwz 12,0xc8(1); mtspr 8,0; lmw 23,0xcc(1); mtcrf 8,12; addi 1,1,240"
extern "C" void _s8014AE3C_0();
extern "C" void _s8014AE3C_1();
extern "C" void _s8014AE3C_2();
extern "C" void _s8014AE3C_3();
extern "C" void _s8014AE3C_4();
extern "C" void _s8014AE3C_5();
extern "C" void _s8014AE3C_6();
extern "C" void _s8014AE3C_7();
extern "C" void _s8014AE3C_8();
extern "C" void _s8014AE3C_9();
extern "C" void _s8014AE3C_10();
extern "C" void _s8014AE3C_11();
extern "C" void _s8014AE3C_12();
extern "C" void _s8014AE3C_13();
extern "C" void _s8014AE3C_14();
extern "C" void _s8014AE3C_15();
extern "C" void _s8014AE3C_16();
extern "C" void _s8014AE3C_17();
extern "C" void _s8014AE3C_18();
extern "C" void _s8014AE3C_19();
extern "C" void _s8014AE3C_20();
extern "C" void _s8014AE3C_21();
extern "C" void _s8014AE3C_22();
extern "C" void _s8014AE3C_23();
extern "C" void _s8014AE3C_24();
extern "C" void _s8014AE3C_25();
extern "C" void _s8014AE3C_26();
extern "C" void _s8014AE3C_27();
extern "C" void _s8014AE3C_28();
extern "C" void _s8014AE3C_29();
extern "C" void _s8014AE3C_30();
extern "C" void _s8014AE3C_31();
extern "C" void _s8014AE3C_32();
extern "C" void _s8014AE3C_33();
extern "C" void _s8014AE3C_34();
extern "C" void _s8014AE3C_35();
extern "C" void _s8014AE3C_36();
extern "C" void _s8014AE3C_37();
extern "C" void _s8014AE3C_38();
extern "C" void _s8014AE3C_39();
extern "C" void _s8014AE3C_40();
extern "C" void _s8014AE3C_41();
extern "C" void f_8014AE3C() {}
