// 0x8026FB50 AptActionInterpreter::getVariable(AptValue (1092 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 23,0x1c(1); stw 0,0x44(1); stw 12,0x18(1); lis 10,-32700; mr 28,6; lhz 11,-6476(10); addi 0,10,-6476; stw 0,0x8(1); mr 25,3; addi 11,11,1; mr 26,4; sth 11,-6476(10); mr 27,5; mr 23,7; mr 24,8; lwz 11,0x0(28); addi 29,1,8; lis 30,-32700; lbz 0,0x8(11); cmpwi 0,36; bne 4f; lwz 31,-26892(13); cmpwi 31,0; beq 2f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 1:; addi 30,31,12; mr 3,30; bl _s8026FB50_0; cmpwi 3,0; bne 3f; mr 3,30; li 4,0; bl _s8026FB50_1; b 3f; 2:; lwz 3,-23020(13); li 4,20; bl _s8026FB50_2; bl _s8026FB50_3; mr 31,3; 3:; mr 4,28; addi 3,31,12; bl _s8026FB50_4; lwz 4,0x8(1); b 27f; 4:; cmpwi 4,9,0; li 31,0; bne cr4,5f; mr 3,26; mr 4,27; mr 5,28; addi 6,1,16; mr 7,29; bl _s8026FB50_5; mr 31,3; b 7f; 5:; stw 26,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026FB50_6; 6:; lwz 0,0x0(28); stw 0,0x8(1); 7:; lwz 4,0x8(1); lis 9,-32700; addi 9,9,-6476; cmpw 4,9; bne 9f; lwz 31,0x10(1); cmpwi 31,0; beq 8f; lhz 9,-6476(30); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,-6476(30); b 28f; 8:; lhz 9,-6476(30); lwz 31,-22936(13); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,-6476(30); b 28f; 9:; cmpwi 31,1; bne 10f; lwz 3,0x10(1); cmpwi 3,0; beq 10f; mr 4,29; mr 5,27; bl _s8026FB50_7; mr. 30,3; bne 23f; 10:; cmpwi 24,0; beq 18f; lwz 9,0x30(25); cmpwi 9,0; beq 18f; lwz 3,-26960(13); cmpwi 3,0; bne 13f; lwz 3,0x2c(9); cmpwi 3,0; beq 12f; mr 31,3; 11:; addi 3,31,12; mr 4,29; bl _s8026FB50_8; mr. 3,3; bne 16f; lwz 31,0x20(31); cmpwi 31,0; bne 11b; b 15f; 12:; li 30,0; b 17f; 13:; mr 31,3; 14:; addi 3,31,12; mr 4,29; bl _s8026FB50_9; mr. 3,3; bne 16f; lwz 31,0x20(31); cmpwi 31,0; bne 14b; 15:; li 3,0; 16:; mr 30,3; 17:; cmpwi 30,0; bne 23f; 18:; lwz 11,0x10(1); cmpwi 11,0; beq 19f; lwz 0,0x0(11); andis. 9,0,2048; bne 20f; 19:; cmpwi 27,0; beq 26f; mr 4,26; li 9,0; mr 3,25; mr 6,28; mr 7,23; li 5,0; li 8,1; bl _s8026FB50_10; lwz 4,0x8(1); mr 31,3; b 27f; 20:; lwz 9,0x8(11); mr 4,11; addi 5,1,8; lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; mr. 30,3; bne 23f; lwz 3,0x10(1); addi 4,1,8; mr 5,27; bl _s8026FB50_11; mr. 30,3; bne 23f; cmpwi 27,0; beq 21f; mr 4,26; li 9,0; mr 3,25; mr 6,28; mr 7,23; li 5,0; li 8,1; bl _s8026FB50_12; lwz 4,0x8(1); mr 31,3; b 27f; 21:; lwz 11,0x10(1); li 0,0; lwz 11,0x0(11); rlwinm 9,11,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 22f; rlwinm 0,11,5,31,31; 22:; cmpwi 0,0; bne 25f; lwz 3,0x30(25); cmpwi 3,0; beq 25f; bne cr4,25f; lwz 3,0x28(3); lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; beq 25f; addi 4,1,8; bl _s8026FB50_13; mr. 30,3; beq 25f; 23:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 24f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026FB50_14; 24:; mr 3,30; b 30f; 25:; lis 9,-32694; lwz 0,-16132(9); cmpwi 0,0; beq 26f; lwz 3,0x0(28); mtspr 8,0; addi 3,3,8; blrl; 26:; lwz 4,0x8(1); lwz 31,-22936(13); 27:; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); 28:; cmpwi 0,0; bne 29f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026FB50_15; 29:; mr 3,31; 30:; lwz 0,0x44(1); lwz 12,0x18(1); mtspr 8,0; lmw 23,0x1c(1); mtcrf 8,12; addi 1,1,64"

extern "C" void _s8026FB50_0();
extern "C" void _s8026FB50_1();
extern "C" void _s8026FB50_2();
extern "C" void _s8026FB50_3();
extern "C" void _s8026FB50_4();
extern "C" void _s8026FB50_5();
extern "C" void _s8026FB50_6();
extern "C" void _s8026FB50_7();
extern "C" void _s8026FB50_8();
extern "C" void _s8026FB50_9();
extern "C" void _s8026FB50_10();
extern "C" void _s8026FB50_11();
extern "C" void _s8026FB50_12();
extern "C" void _s8026FB50_13();
extern "C" void _s8026FB50_14();
extern "C" void _s8026FB50_15();

struct AptActionInterpreter {
    void getVariable();
};

void AptActionInterpreter::getVariable() {
}
