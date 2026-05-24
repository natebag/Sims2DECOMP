// 0x8031E838 ERShader::OldLoad(EFile (1328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 30,4; mr 27,3; lwz 9,0x28(30); mr 31,5; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x28(30); addi 4,1,8; li 5,20; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,0x10(27); lwz 9,0x18(1); lwz 11,0x8(1); rlwimi 0,9,8,0,23; stw 0,0x10(27); cmpwi 11,17; ble 33f; bl _s8031E838_0; lwz 4,0x18(1); li 5,0; bl _s8031E838_1; lwz 9,0x28(30); mr 25,3; mr 4,25; lwz 5,0x18(1); lwz 0,0x1c(9); mr 26,25; lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; mr 3,26; bl _s8031E838_2; lwz 0,0xc(1); addi 3,3,1; add 26,26,3; cmpwi 0,1; bne 0f; mr 4,26; mr 3,27; mr 5,31; bl _s8031E838_3; bl _s8031E838_4; mr 4,25; bl _s8031E838_5; b 33f; 0:; lwz 0,0x58(27); lwz 11,0x8(1); rlwinm 0,0,0,31,29; addi 9,11,-21; stw 0,0x58(27); cmplwi 9,1; bgt 1f; mr 5,26; mr 3,27; mr 4,31; bl _s8031E838_6; b 2f; 1:; cmpwi 11,20; bne 3f; mr 5,26; mr 3,27; mr 4,31; bl _s8031E838_7; 2:; mr 26,3; 3:; lbz 0,0x0(31); li 11,0; addi 8,31,48; cmpw 11,0; bge 7f; li 10,2; li 7,127; mr 9,31; 4:; lwz 0,0x70(9); andi. 0,0,64; bne 5f; stb 0,0x83(9); stb 10,0x80(9); stb 10,0x81(9); stb 10,0x82(9); b 6f; 5:; lbz 0,0x80(9); cmpwi 0,0; bne 6f; lbz 0,0x81(9); cmpwi 0,2; bne 6f; lbz 0,0x82(9); cmpwi 0,2; bne 6f; lbz 0,0x83(9); cmpwi 0,1; bne 6f; lbz 0,0x84(9); andi. 6,0,128; beq 6f; stb 7,0x84(9); 6:; lbz 0,0x0(31); addi 11,11,1; addi 9,9,64; cmpw 11,0; blt 4b; 7:; li 0,3; lis 9,-32702; mtspr 9,0; lfs f13,0xa88(9); mr 11,8; li 9,0; 8:; lfsx f0,9,11; fcmpu 0,f0,f13; ble 9f; stfsx f13,9,8; 9:; addi 9,9,4; bdnz 8b; lwz 0,0x8(1); cmpwi 0,19; ble 15f; lwz 0,0x4(31); andis. 6,0,1024; beq 15f; lbz 28,0x88(31); cmpwi 28,0; ble 10f; rlwinm 30,28,2,0,29; lis 29,-32692; mr 4,30; li 5,8; addi 3,29,-17444; bl _s8031E838_8; mr 0,3; mr 4,26; stw 0,0x68(31); mr 5,30; add 26,26,30; bl _s8031E838_9; mr 4,30; li 5,8; addi 3,29,-17444; bl _s8031E838_10; mr 0,3; li 4,0; stw 0,0x34(27); mr 5,30; bl _s8031E838_11; mr 4,30; li 5,8; addi 3,29,-17444; bl _s8031E838_12; mr 0,3; mr 5,30; stw 0,0x38(27); li 4,0; bl _s8031E838_13; stw 28,0x30(27); 10:; addi 8,31,100; cmpwi 28,0; beq 14f; mtspr 9,28; li 7,1; li 10,0; 11:; lwz 9,0x4(8); lwzx 0,10,9; cmpwi 0,0; beq 12f; lwz 9,0x38(27); stwx 0,10,9; lwz 11,0x4(8); stwx 7,10,11; b 13f; 12:; stwx 0,10,9; 13:; addi 10,10,4; bdnz 11b; 14:; lhz 4,0x8a(31); cmpwi 4,0; beq 19f; lis 3,-32692; li 5,8; addi 3,3,-17444; bl _s8031E838_14; mr 0,3; lhz 5,0x8a(31); mr 4,26; stw 0,0x6c(31); bl _s8031E838_15; b 19f; 15:; lbz 0,0x0(31); li 10,0; cmpw 10,0; bge 19f; li 8,1; addi 11,27,40; li 9,100; 16:; lwzx 0,9,31; cmpwi 0,0; beq 17f; stw 0,0x0(11); stwx 8,9,31; b 18f; 17:; stwx 0,9,31; 18:; lbz 0,0x0(31); addi 10,10,1; addi 11,11,4; addi 9,9,64; cmpw 10,0; blt 16b; 19:; bl _s8031E838_16; mr 4,25; bl _s8031E838_17; lbz 0,0x0(31); li 8,0; li 10,0; cmpw 8,0; bge 25f; lis 9,-32702; li 6,5; lfs f13,0xa8c(9); li 7,6; addi 11,31,100; 20:; lfs f0,0x28(11); fcmpu 0,f0,f13; bne 21f; lfs f0,0x2c(11); fcmpu 0,f0,f13; beq 23f; 21:; lwz 0,0x4(31); oris 0,0,32768; stw 0,0x4(31); lwz 0,0x10(11); lbz 9,0x22(11); ori 0,0,64; cmpwi 9,0; stw 0,0x10(11); bne 22f; stb 6,0x22(11); b 23f; 22:; cmpwi 9,1; bne 23f; stb 7,0x22(11); 23:; lbz 9,0x22(11); addi 9,9,-4; cmplwi 9,2; bgt 24f; li 8,1; 24:; lbz 0,0x0(31); addi 10,10,1; addi 11,11,64; cmpw 10,0; blt 20b; 25:; cmpwi 8,0; beq 26f; lwz 0,0x4(31); oris 0,0,2048; stw 0,0x4(31); 26:; lwz 0,0x8(1); cmpwi 0,19; ble 29f; lwz 0,0x4(31); andis. 6,0,1024; beq 29f; lwz 0,0x30(27); li 29,0; cmplw 29,0; bge 33f; lis 28,-32692; 27:; lwz 9,0x68(31); rlwinm 30,29,2,0,29; lwzx 0,30,9; cmpwi 0,0; beq 28f; lwz 9,0x38(27); addi 3,28,-7364; li 5,0; li 6,0; lwzx 4,30,9; bl _s8031E838_18; lwz 9,0x34(27); stwx 3,30,9; lwz 11,0x34(27); lwz 10,0x68(31); lwzx 9,30,11; lwz 0,0x14(9); stwx 0,30,10; 28:; addi 0,29,1; lwz 9,0x30(27); rlwinm 29,0,0,24,31; cmplw 29,9; blt 27b; b 33f; 29:; lbz 0,0x0(31); li 28,0; cmpw 28,0; bge 33f; addi 29,27,32; addi 30,31,100; lis 27,-32692; 30:; lwz 0,0x0(30); cmpwi 0,0; beq 32f; lwz 4,0x8(29); addi 3,27,-7364; li 5,0; li 6,0; bl _s8031E838_19; stw 3,0x0(29); cmpwi 3,0; beq 31f; lwz 0,0x14(3); stw 0,0x0(30); b 32f; 31:; stw 3,0x0(30); 32:; lbz 0,0x0(31); addi 28,28,1; addi 30,30,64; addi 29,29,4; cmpw 28,0; blt 30b; 33:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"

extern "C" void _s8031E838_0();
extern "C" void _s8031E838_1();
extern "C" void _s8031E838_2();
extern "C" void _s8031E838_3();
extern "C" void _s8031E838_4();
extern "C" void _s8031E838_5();
extern "C" void _s8031E838_6();
extern "C" void _s8031E838_7();
extern "C" void _s8031E838_8();
extern "C" void _s8031E838_9();
extern "C" void _s8031E838_10();
extern "C" void _s8031E838_11();
extern "C" void _s8031E838_12();
extern "C" void _s8031E838_13();
extern "C" void _s8031E838_14();
extern "C" void _s8031E838_15();
extern "C" void _s8031E838_16();
extern "C" void _s8031E838_17();
extern "C" void _s8031E838_18();
extern "C" void _s8031E838_19();

struct ERShader {
    void OldLoad();
};

void ERShader::OldLoad() {
}
