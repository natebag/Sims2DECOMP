// 0x8026E69C AptActionInterpreter::cbCallMethod_isNaN(AptValue (1196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); cmpwi 4,0; bne 0f; lwz 3,-26916(13); li 31,1; cmpwi 3,0; beq 28f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; bge 25f; b 26f; 0:; lis 9,-32694; li 10,0; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); lwz 9,0x0(3); rlwinm 0,9,0,25,31; cmpwi 0,7; bne 1f; rlwinm 10,9,5,31,31; 1:; cmpwi 10,0; bne 20f; li 11,0; cmpwi 0,6; bne 2f; rlwinm 11,9,5,31,31; 2:; cmpwi 11,0; bne 20f; li 11,0; cmpwi 0,1; beq 3f; cmpwi 0,42; bne 4f; 3:; andis. 0,9,2048; beq 4f; li 11,1; 4:; cmpwi 11,0; beq 21f; lis 11,-32700; addi 4,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); bl _s8026E69C_0; lwz 4,0x8(1); lhz 11,0x2(4); cmpwi 11,0; bne 5f; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_1; b 23f; 5:; lbz 0,0x8(4); addi 3,4,8; cmpwi 0,48; bne 6f; cmpwi 11,2; ble 6f; lbz 0,0x1(3); cmpwi 0,120; bne 6f; addi 4,1,16; li 5,16; bl _s8026E69C_2; lwz 9,0x10(1); lbz 0,0x0(9); cmpwi 0,0; bne 6f; lwz 4,0x8(1); b 19f; 6:; lwz 9,0x8(1); li 7,0; lhz 11,0x2(9); mr 4,9; add 11,11,9; lbz 0,0x7(11); extsb 0,0; cmpwi 0,45; beq 7f; cmpwi 0,43; beq 7f; cmpwi 0,101; beq 7f; cmpwi 0,46; beq 7f; lis 9,-32704; addi 9,9,-935; lbzx 0,9,0; andi. 9,0,4; bne 7f; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_3; b 23f; 7:; lbz 0,0x8(4); extsb 0,0; cmpwi 0,46; beq 8f; cmpwi 0,45; beq 8f; cmpwi 0,43; beq 8f; lis 9,-32704; addi 9,9,-935; lbzx 0,9,0; andi. 9,0,4; beq 9f; 8:; li 10,1; b 10f; 9:; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_4; b 23f; 10:; lhz 0,0x2(4); cmpw 10,0; bge 19f; lis 9,-32704; addi 0,10,8; addi 8,9,-935; add 11,0,4; 11:; lbz 0,0x0(11); cmpwi 0,46; bne 12f; cmpwi 7,0; bne 12f; li 7,1; b 18f; 12:; lbz 0,0x0(11); cmpwi 0,101; bne 17f; cmpwi 10,1; beq 17f; cmpwi 10,2; bne 14f; lbz 0,0x8(4); extsb 0,0; cmpwi 0,43; beq 13f; cmpwi 0,45; bne 14f; 13:; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_5; b 23f; 14:; lhz 9,0x2(4); addi 0,10,1; cmpw 0,9; bge 18f; lbz 0,0x1(11); extsb 0,0; cmpwi 0,45; beq 15f; cmpwi 0,43; beq 15f; lbzx 0,8,0; andi. 9,0,4; beq 16f; 15:; addi 11,11,1; addi 10,10,1; b 18f; 16:; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_6; b 23f; 17:; lbz 0,0x0(11); extsb 0,0; lbzx 9,8,0; andi. 0,9,4; bne 18f; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 23f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_7; b 23f; 18:; lhz 0,0x2(4); addi 10,10,1; addi 11,11,1; cmpw 10,0; blt 11b; 19:; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 20f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026E69C_8; 20:; li 31,0; b 24f; 21:; lwz 0,0x0(3); andis. 9,0,2048; beq 22f; rlwinm 0,0,0,25,31; cmpwi 0,3; bne 23f; 22:; bl _s8026E69C_9; xori 31,3,7; subfic 0,31,0; adde 31,0,31; b 24f; 23:; li 31,1; 24:; lwz 3,-26916(13); cmpwi 3,0; beq 28f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 26f; 25:; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 27f; 26:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 27:; stw 31,0xc(3); b 29f; 28:; lwz 3,-23020(13); li 4,16; bl _s8026E69C_10; mr 30,3; li 4,5; bl _s8026E69C_11; lis 9,-32702; stw 31,0xc(30); addi 9,9,-29224; mr 3,30; stw 9,0x8(30); 29:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s8026E69C_0();
extern "C" void _s8026E69C_1();
extern "C" void _s8026E69C_2();
extern "C" void _s8026E69C_3();
extern "C" void _s8026E69C_4();
extern "C" void _s8026E69C_5();
extern "C" void _s8026E69C_6();
extern "C" void _s8026E69C_7();
extern "C" void _s8026E69C_8();
extern "C" void _s8026E69C_9();
extern "C" void _s8026E69C_10();
extern "C" void _s8026E69C_11();

struct AptActionInterpreter {
    void cbCallMethod_isNaN();
};

void AptActionInterpreter::cbCallMethod_isNaN() {
}
