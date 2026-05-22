// 0x8030A604 LZSSCompressor::Encode(unsigned (796 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 22,0x20(1); stw 0,0x4c(1); add 6,5,6; li 30,0; add 4,3,4; stw 6,-26676(13); stw 4,-26684(13); li 25,4078; stw 5,-26680(13); li 23,1; stw 3,-26688(13); li 28,1; stw 30,-26672(13); li 26,0; stw 30,-26696(13); li 31,0; stw 30,-26692(13); bl _s8030A604_0; li 4,4113; li 5,0; bl _s8030A604_1; stw 3,-22680(13); bl _s8030A604_2; li 4,8194; li 5,0; bl _s8030A604_3; stw 3,-22668(13); bl _s8030A604_4; li 4,8706; li 5,0; bl _s8030A604_5; stw 3,-22664(13); bl _s8030A604_6; li 4,8194; li 5,0; bl _s8030A604_7; stw 3,-22660(13); bl _s8030A604_8; mtspr 9,25; stb 30,0x8(1); li 0,0; 0:; lwz 9,-22680(13); stbx 0,9,31; addi 31,31,1; bdnz 0b; li 27,0; b 2f; 1:; lwz 11,-22680(13); addi 9,27,4078; addi 27,27,1; stbx 30,11,9; 2:; cmpwi 27,17; bgt 3f; bl _s8030A604_9; mr 30,3; cmpwi 30,-1; bne 1b; 3:; stw 27,-26696(13); cmpwi 27,0; bne 4f; li 3,0; b 23f; 4:; addi 24,1,8; li 30,4077; li 31,18; 5:; mr 3,30; bl _s8030A604_10; addi 30,30,-1; addic. 31,31,-1; bne 5b; li 3,4078; bl _s8030A604_11; mr 22,24; 6:; lwz 0,-22672(13); cmpw 0,27; ble 7f; stw 27,-22672(13); 7:; lwz 0,-22672(13); cmpwi 0,2; bgt 8f; lbz 9,0x8(1); li 0,1; stw 0,-22672(13); or 9,23,9; lwz 11,-22680(13); stb 9,0x8(1); lbzx 0,11,25; stbx 0,24,28; b 9f; 8:; lwz 0,-22676(13); lbz 11,-22673(13); lbz 9,-22669(13); srawi 0,0,4; stbx 11,22,28; rlwinm 0,0,0,0,27; addi 9,9,-3; addi 28,28,1; or 0,0,9; stbx 0,22,28; 9:; addi 28,28,1; rlwinm. 23,23,1,24,30; bne 12f; li 31,0; cmpw 31,28; bge 11f; 10:; lbzx 3,24,31; addi 31,31,1; bl _s8030A604_12; cmpw 31,28; blt 10b; 11:; lwz 9,-26692(13); li 0,0; stb 0,0x8(1); li 23,1; add 9,9,28; stw 9,-26692(13); li 28,1; 12:; lwz 29,-22672(13); li 31,0; b 15f; 13:; mr 3,26; bl _s8030A604_13; lwz 9,-22680(13); cmpwi 26,16; stbx 30,9,26; bgt 14f; lwz 9,-22680(13); add 9,26,9; stb 30,0x1000(9); 14:; addi 0,25,1; addi 9,26,1; rlwinm 25,0,0,20,31; rlwinm 26,9,0,20,31; mr 3,25; addi 31,31,1; bl _s8030A604_14; 15:; cmpw 31,29; bge 16f; bl _s8030A604_15; mr 30,3; cmpwi 30,-1; bne 13b; 16:; mr 0,31; cmpw 0,29; addi 31,31,1; bge 19f; 17:; mr 3,26; bl _s8030A604_16; addi 0,26,1; addi 9,25,1; rlwinm 26,0,0,20,31; rlwinm 25,9,0,20,31; addic. 27,27,-1; beq 18f; mr 3,25; bl _s8030A604_17; 18:; mr 0,31; cmpw 0,29; addi 31,31,1; blt 17b; 19:; cmpwi 27,0; bgt 6b; cmpwi 28,1; ble 22f; li 31,0; cmpw 31,28; bge 21f; 20:; lbzx 3,24,31; addi 31,31,1; bl _s8030A604_18; cmpw 31,28; blt 20b; 21:; lwz 0,-26692(13); add 0,0,28; stw 0,-26692(13); 22:; bl _s8030A604_19; lwz 4,-22680(13); bl _s8030A604_20; bl _s8030A604_21; lwz 4,-22668(13); bl _s8030A604_22; bl _s8030A604_23; lwz 4,-22664(13); bl _s8030A604_24; bl _s8030A604_25; lwz 4,-22660(13); bl _s8030A604_26; lwz 0,-26672(13); cmpwi 0,0; li 3,-1; bne 23f; lwz 3,-26692(13); 23:; lwz 0,0x4c(1); mtspr 8,0; lmw 22,0x20(1); addi 1,1,72"
extern "C" void _s8030A604_0();
extern "C" void _s8030A604_1();
extern "C" void _s8030A604_2();
extern "C" void _s8030A604_3();
extern "C" void _s8030A604_4();
extern "C" void _s8030A604_5();
extern "C" void _s8030A604_6();
extern "C" void _s8030A604_7();
extern "C" void _s8030A604_8();
extern "C" void _s8030A604_9();
extern "C" void _s8030A604_10();
extern "C" void _s8030A604_11();
extern "C" void _s8030A604_12();
extern "C" void _s8030A604_13();
extern "C" void _s8030A604_14();
extern "C" void _s8030A604_15();
extern "C" void _s8030A604_16();
extern "C" void _s8030A604_17();
extern "C" void _s8030A604_18();
extern "C" void _s8030A604_19();
extern "C" void _s8030A604_20();
extern "C" void _s8030A604_21();
extern "C" void _s8030A604_22();
extern "C" void _s8030A604_23();
extern "C" void _s8030A604_24();
extern "C" void _s8030A604_25();
extern "C" void _s8030A604_26();
extern "C" void f_8030A604() {}
