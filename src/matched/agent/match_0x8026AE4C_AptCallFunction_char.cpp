// 0x8026AE4C AptCallFunction(char (1016 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-344(1); mfspr 0,8; mfcr 12; stmw 20,0x128(1); stw 0,0x15c(1); stw 12,0x124(1); lis 0,1024; addi 11,1,352; addi 30,1,8; mr 22,4; stw 0,0x108(1); mr 21,3; stw 11,0x10c(1); mr 4,5; stw 30,0x110(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,0f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 0:; mr 25,6; cmpwi 4,0; beq 1f; addi 3,1,240; lis 23,-32694; bl _s8026AE4C_0; addi 30,1,240; li 3,0; bl _s8026AE4C_1; mr 20,30; mr 4,3; li 9,0; lis 3,-32694; li 5,0; addi 3,3,-16032; mr 6,30; li 7,1; li 8,1; bl _s8026AE4C_2; lwz 4,0xf0(1); mr 24,3; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026AE4C_3; b 2f; 1:; li 3,0; addi 20,1,240; bl _s8026AE4C_4; lis 23,-32694; mr 24,3; 2:; lwz 0,0x108(1); addi 9,1,264; lwz 10,0x8(9); addi 11,1,248; lwz 8,0x4(9); li 28,0; stw 0,0xf8(1); cmpw 28,25; stw 10,0x8(11); addi 27,25,-1; stw 8,0x4(11); cmpwi 4,22,0; bge 12f; li 31,0; 3:; lwz 30,-26892(13); cmpwi 30,0; beq 7f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 4f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 5f; 4:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 5:; addi 29,30,12; mr 3,29; bl _s8026AE4C_5; cmpwi 3,0; bne 6f; mr 3,29; li 4,0; bl _s8026AE4C_6; 6:; mr 3,30; b 8f; 7:; lwz 3,-23020(13); li 4,20; bl _s8026AE4C_7; bl _s8026AE4C_8; 8:; addi 9,1,112; mr 10,31; stwx 3,9,31; mr 8,9; lbz 11,0xf8(1); extsb 9,11; addi 0,9,1; cmplwi 0,8; bgt 9f; lwz 0,0x100(1); rlwinm 9,9,2,0,29; addi 11,11,1; add 4,0,9; stb 11,0xf8(1); b 11f; 9:; cmpwi 9,7; bgt 10f; lwz 4,0xfc(1); li 0,8; stb 0,0xf8(1); addi 9,4,4; stw 9,0xfc(1); b 11f; 10:; lwz 4,0xfc(1); addi 0,4,4; stw 0,0xfc(1); 11:; lwzx 30,8,10; addi 3,1,280; lwz 4,0x0(4); addi 28,28,1; addi 30,30,12; addi 31,31,4; bl _s8026AE4C_9; addi 4,1,280; mr 3,30; bl _s8026AE4C_10; addi 3,1,280; li 4,2; bl _s8026AE4C_11; cmpw 28,25; blt 3b; 12:; mr. 28,27; blt 14f; lis 29,-32694; addi 9,1,112; rlwinm 0,28,2,0,29; addi 26,29,-16032; add 30,9,0; lis 27,-32704; lis 31,-32704; 13:; lwz 11,-16032(29); addi 4,27,3088; lwz 10,0x0(30); addi 5,31,3140; lwz 8,0x8(26); rlwinm 9,11,2,0,29; addi 11,11,1; li 6,138; stwx 10,9,8; addi 30,30,-4; stw 11,-16032(29); lwz 9,0x8(10); lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; addic. 28,28,-1; bge 13b; 14:; addi 3,1,240; mr 4,21; bl _s8026AE4C_12; lis 30,-32694; mr 6,20; mr 4,24; li 5,0; li 7,1; li 8,1; li 9,0; addi 3,30,-16032; bl _s8026AE4C_13; mr 29,3; bl _s8026AE4C_14; mr 28,3; mr 4,24; addi 3,30,-16032; mr 5,29; mr 6,25; bl _s8026AE4C_15; mr 3,28; bl _s8026AE4C_16; beq cr4,15f; addi 9,23,-16032; lwz 11,-16032(23); lwz 0,0x8(9); mr 4,22; rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s8026AE4C_17; 15:; lwz 9,-16032(23); addi 11,23,-16032; cmpwi 9,0; ble 16f; lwz 0,0x8(11); rlwinm 9,9,2,0,29; lis 4,-32704; lis 5,-32704; add 9,9,0; addi 4,4,3292; lwz 11,-4(9); addi 5,5,3140; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,-16032(23); addi 9,9,-1; stw 9,-16032(23); 16:; lwz 4,0xf0(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 17f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026AE4C_18; 17:; lwz 0,0x15c(1); lwz 12,0x124(1); mtspr 8,0; lmw 20,0x128(1); mtcrf 8,12; addi 1,1,344"
extern "C" void _s8026AE4C_0();
extern "C" void _s8026AE4C_1();
extern "C" void _s8026AE4C_2();
extern "C" void _s8026AE4C_3();
extern "C" void _s8026AE4C_4();
extern "C" void _s8026AE4C_5();
extern "C" void _s8026AE4C_6();
extern "C" void _s8026AE4C_7();
extern "C" void _s8026AE4C_8();
extern "C" void _s8026AE4C_9();
extern "C" void _s8026AE4C_10();
extern "C" void _s8026AE4C_11();
extern "C" void _s8026AE4C_12();
extern "C" void _s8026AE4C_13();
extern "C" void _s8026AE4C_14();
extern "C" void _s8026AE4C_15();
extern "C" void _s8026AE4C_16();
extern "C" void _s8026AE4C_17();
extern "C" void _s8026AE4C_18();
extern "C" void f_8026AE4C() {}
