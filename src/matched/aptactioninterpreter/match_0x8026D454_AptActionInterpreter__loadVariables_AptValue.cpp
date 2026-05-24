// 0x8026D454 AptActionInterpreter::loadVariables(AptValue (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 27,3; mr 25,4; mr 26,5; mr. 6,6; bne 0f; lis 9,-32694; lwz 0,-16232(9); mtspr 8,0; blrl; b 1f; 0:; lis 9,-32694; lwz 3,0x0(6); lwz 0,-16236(9); addi 3,3,8; mtspr 8,0; blrl; 1:; lwz 0,0x0(3); li 31,0; li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 2f; cmpwi 0,42; bne 3f; 2:; andis. 0,9,2048; beq 3f; li 11,1; 3:; cmpwi 11,0; beq 5f; rlwinm 0,9,0,25,31; mr 10,3; cmpwi 0,1; beq 4f; lwz 10,0x24(3); 4:; addi 31,10,12; b 6f; 5:; li 4,0; bl _s8026D454_0; 6:; lis 11,-32700; lwz 10,0x0(31); lhz 9,-6476(11); addi 0,11,-6476; addi 29,10,8; stw 0,0x10(1); addi 9,9,2; stw 0,0x8(1); sth 9,-6476(11); addi 28,1,16; b 14f; 7:; lwz 0,0x8(1); lis 9,-32700; addi 9,9,-6476; cmpw 0,9; beq 14f; lwz 31,-26892(13); cmpwi 31,0; beq 11f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 8f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 9f; 8:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 9:; addi 30,31,12; mr 3,30; bl _s8026D454_1; cmpwi 3,0; bne 10f; mr 3,30; li 4,0; bl _s8026D454_2; 10:; mr 30,31; b 12f; 11:; lwz 3,-23020(13); li 4,20; bl _s8026D454_3; bl _s8026D454_4; mr 30,3; 12:; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 13f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D454_5; 13:; lwz 0,0x10(1); mr 7,30; mr 3,27; mr 4,25; stw 0,0xc(30); mr 5,26; addi 6,1,8; li 8,1; li 9,1; li 10,0; bl _s8026D454_6; 14:; mr 4,29; mr 3,27; addi 5,1,8; mr 6,28; bl _s8026D454_7; mr. 29,3; bne 7b; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 15f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D454_8; 15:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 16f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D454_9; 16:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s8026D454_0();
extern "C" void _s8026D454_1();
extern "C" void _s8026D454_2();
extern "C" void _s8026D454_3();
extern "C" void _s8026D454_4();
extern "C" void _s8026D454_5();
extern "C" void _s8026D454_6();
extern "C" void _s8026D454_7();
extern "C" void _s8026D454_8();
extern "C" void _s8026D454_9();

struct AptActionInterpreter {
    void loadVariables();
};

void AptActionInterpreter::loadVariables() {
}
