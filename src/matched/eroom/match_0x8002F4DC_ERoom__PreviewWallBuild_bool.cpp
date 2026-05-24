// 0x8002F4DC ERoom::PreviewWallBuild(bool) (832 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; stmw 21,0x8c(1); stw 0,0xbc(1); lwz 11,-21488(13); mr 25,3; mr 27,4; li 26,0; lwz 9,0x0(11); li 4,0; li 28,0; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; lwz 31,-21472(13); lwz 9,0x4(31); lwz 29,0x8(9); stw 29,0x8(1); mr 30,29; lwz 0,0x4(31); cmpw 29,0; stw 0,0x8(1); beq 2f; 0:; lwz 3,0x14(30); cmpwi 3,0; beq 1f; lwz 0,0x34(3); cmpwi 0,0; beq 1f; bl _s8002F4DC_0; cmpwi 3,0; bne 1f; lhz 0,0x10(30); cmplw 0,28; ble 1f; mr 28,0; 1:; mr 3,30; bl _s8002F4DC_1; lwz 0,0x4(31); mr 30,3; cmpw 30,0; stw 0,0x8(1); bne 0b; 2:; cmpwi 28,39; ble 5f; b 19f; 3:; lwz 3,0x14(29); lwz 0,0x34(3); cmpwi 0,0; beq 4f; bl _s8002F4DC_2; cmpwi 3,0; bne 4f; addi 26,26,1; 4:; mr 3,29; bl _s8002F4DC_3; mr 29,3; 5:; lwz 0,0x4(31); li 9,1; cmpw 29,0; bne 6f; li 9,0; 6:; cmpwi 9,0; bne 3b; cmpwi 26,19; bgt 19f; cmpwi 27,0; beq 18f; lwz 28,-21488(13); addi 30,1,16; li 25,1; mr 26,30; lwz 9,0x0(28); li 24,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x0(28); addi 21,3,-1; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,28,3; blrl; addi 23,3,-1; addi 3,1,8; bl _s8002F4DC_4; mr 3,30; bl _s8002F4DC_5; li 0,1; cmpw 25,21; stb 0,0xa(1); bge 16f; 7:; li 30,1; addi 22,25,1; cmpw 30,23; bge 15f; mr 31,26; addi 29,1,72; 8:; stb 30,0x9(1); addi 5,1,8; stb 25,0x8(1); mr 3,29; addi 27,30,1; lwz 9,0x0(28); lha 4,0xa8(9); lwz 0,0xac(9); add 4,28,4; mtspr 8,0; blrl; mr 4,29; mr 3,31; bl _s8002F4DC_6; mr 3,29; li 4,2; bl _s8002F4DC_7; mr 3,31; bl _s8002F4DC_8; mr. 30,3; beq 14f; 9:; addi 0,30,-1; cmplwi 0,1; ble 13f; mr 3,26; mr 4,30; bl _s8002F4DC_9; cmpwi 3,2; beq 10f; cmpwi 3,12; beq 10f; cmpwi 3,13; beq 10f; cmpwi 3,14; bne 11f; 10:; li 0,1; b 12f; 11:; li 0,0; 12:; cmpwi 0,0; beq 13f; addi 24,24,1; 13:; mr 4,30; mr 3,26; bl _s8002F4DC_10; mr. 30,3; bne 9b; 14:; rlwinm 30,27,0,24,31; cmpw 30,23; blt 8b; 15:; rlwinm 25,22,0,24,31; cmpw 25,21; blt 7b; 16:; cmpwi 24,99; ble 17f; mr 3,26; li 4,2; bl _s8002F4DC_11; addi 3,1,8; li 4,2; bl _s8002F4DC_12; b 19f; 17:; mr 3,26; li 4,2; bl _s8002F4DC_13; addi 3,1,8; li 4,2; bl _s8002F4DC_14; li 3,1; b 20f; 18:; addi 30,1,128; addi 29,1,132; stw 27,0x84(1); mr 3,25; stw 27,0x80(1); li 4,1; mr 5,30; mr 6,29; li 7,0; bl _s8002F4DC_15; mr 3,25; li 4,0; mr 5,30; mr 6,29; li 7,0; bl _s8002F4DC_16; mr 3,25; mr 4,30; mr 5,29; li 6,0; bl _s8002F4DC_17; lwz 0,0x80(1); cmpwi 0,499; bgt 19f; lwz 0,0x84(1); cmpwi 7,0,999; cror 31,30,28; mfcr 3; rlwinm 3,3,0,31,31; b 20f; 19:; li 3,0; 20:; lwz 0,0xbc(1); mtspr 8,0; lmw 21,0x8c(1); addi 1,1,184"

extern "C" void _s8002F4DC_0();
extern "C" void _s8002F4DC_1();
extern "C" void _s8002F4DC_2();
extern "C" void _s8002F4DC_3();
extern "C" void _s8002F4DC_4();
extern "C" void _s8002F4DC_5();
extern "C" void _s8002F4DC_6();
extern "C" void _s8002F4DC_7();
extern "C" void _s8002F4DC_8();
extern "C" void _s8002F4DC_9();
extern "C" void _s8002F4DC_10();
extern "C" void _s8002F4DC_11();
extern "C" void _s8002F4DC_12();
extern "C" void _s8002F4DC_13();
extern "C" void _s8002F4DC_14();
extern "C" void _s8002F4DC_15();
extern "C" void _s8002F4DC_16();
extern "C" void _s8002F4DC_17();

struct ERoom {
    void PreviewWallBuild();
};

void ERoom::PreviewWallBuild() {
}
