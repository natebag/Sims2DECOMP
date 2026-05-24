// 0x800CAF58 Neighbor::ForceNewTree(unsigned (888 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; mfcr 12; stmw 23,0x34(1); stw 0,0x5c(1); stw 12,0x30(1); lis 9,-32697; mr 29,3; mr 25,4; lwz 3,0x5eec(9); bl _s800CAF58_0; mr. 23,3; beq 18f; lhz 0,0x2(23); andi. 9,0,1; beq 7f; li 3,0; addi 4,1,24; addi 5,1,28; addi 28,29,408; bl _s800CAF58_1; lwz 31,0x18(1); lwz 0,0x1c(1); cmplw 31,0; bge 4f; mulli 30,31,12; lha 27,-21222(13); li 26,0; 0:; lwz 9,0x194(29); li 11,1; add 3,30,9; lwz 0,0x4(3); cmpwi 0,0; bne 1f; li 11,0; 1:; cmpwi 11,0; beq 3f; bl _s800CAF58_2; cmpwi 3,0; beq 3f; lwz 4,0x194(29); mr 3,29; add 4,4,30; bl _s800CAF58_3; cmpw 3,27; beq 2f; rlwinm 0,3,2,0,29; stwx 26,28,0; 2:; lwz 3,0x194(29); add 3,3,30; bl _s800CAF58_4; 3:; lwz 0,0x1c(1); addi 31,31,1; addi 30,30,12; cmplw 31,0; blt 0b; 4:; mr 30,28; li 31,0; 5:; lwz 0,0x0(30); addi 30,30,4; cmpwi 0,0; bne 6f; mr 4,31; mr 3,29; bl _s800CAF58_5; mr 3,29; mr 4,31; li 5,2; bl _s800CAF58_6; 6:; addi 31,31,1; cmplwi 31,6; ble 5b; 7:; li 4,0; mr 3,23; bl _s800CAF58_7; mr 31,3; bl _s800CAF58_8; lbz 0,0x2(3); mr 3,31; xori 30,0,128; subfic 9,30,0; adde 30,9,30; bl _s800CAF58_9; lbz 0,0xb(3); li 7,0; cmpwi 0,2; bne 8f; lhz 7,0x8(31); 8:; lha 5,-21218(13); mr 4,25; mr 6,31; addi 3,1,8; bl _s800CAF58_10; addi 3,1,8; mr 4,29; li 5,0; bl _s800CAF58_11; cmpwi 3,0; li 3,0; beq 22f; mr 3,29; addi 4,1,8; bl _s800CAF58_12; li 31,0; mr 26,3; cmpwi 26,-1; bne 9f; addi 4,1,32; addi 5,1,36; mr 3,30; bl _s800CAF58_13; lwz 4,0x20(1); mr 3,29; lwz 5,0x24(1); bl _s800CAF58_14; mr 26,3; cmpwi 26,-1; beq 18f; mulli 10,26,12; lwz 9,0x194(29); lwz 8,0x8(1); addi 11,1,8; lwz 7,0x8(11); mr 4,29; lwz 0,0x4(11); stwx 8,10,9; add 9,10,9; stw 7,0x8(9); stw 0,0x4(9); lwz 3,0x194(29); add 3,3,10; bl _s800CAF58_15; cmpwi 3,0; beq 9f; mr 3,29; mr 4,26; bl _s800CAF58_16; li 31,1; lhz 0,0x2(23); andi. 9,0,1; beq 21f; 9:; cmpwi 4,31,0; bne cr4,10f; mulli 0,26,12; lwz 4,0x194(29); mr 3,29; add 4,4,0; bl _s800CAF58_17; cmpwi 3,-1; bne 21f; 10:; mr 3,30; addi 4,1,40; addi 5,1,44; mulli 24,26,12; bl _s800CAF58_18; li 25,10000; lwz 30,0x28(1); li 28,-1; rlwinm 9,30,2,0,29; addi 9,9,408; add 27,9,29; b 14f; 11:; mr 3,31; bl _s800CAF58_19; cmpwi 3,0; bne 13f; lhz 0,0x2(23); andi. 9,0,1; beq 12f; lwz 3,0x194(29); add 3,3,24; bl _s800CAF58_20; cmpwi 3,0; beq 16f; 12:; mr 4,31; mr 3,29; bl _s800CAF58_21; cmpw 3,25; bge 13f; mr 25,3; mr 28,30; 13:; addi 30,30,1; 14:; lwz 0,0x2c(1); cmplw 30,0; bge 17f; lwz 31,0x0(27); li 9,1; addi 27,27,4; lwz 0,0x4(31); cmpwi 0,0; bne 15f; li 9,0; 15:; cmpwi 9,0; bne 11b; 16:; mr 28,30; 17:; cmpwi 28,-1; bne 19f; 18:; li 3,0; b 22f; 19:; beq cr4,20f; mr 3,29; mr 4,28; bl _s800CAF58_22; b 21f; 20:; mulli 10,26,12; lwz 0,0x194(29); rlwinm 11,28,2,0,29; addi 9,29,408; mr 3,29; mr 4,28; li 5,2; add 0,0,10; stwx 0,9,11; bl _s800CAF58_23; 21:; li 3,1; 22:; lwz 0,0x5c(1); lwz 12,0x30(1); mtspr 8,0; lmw 23,0x34(1); mtcrf 8,12; addi 1,1,88"

extern "C" void _s800CAF58_0();
extern "C" void _s800CAF58_1();
extern "C" void _s800CAF58_2();
extern "C" void _s800CAF58_3();
extern "C" void _s800CAF58_4();
extern "C" void _s800CAF58_5();
extern "C" void _s800CAF58_6();
extern "C" void _s800CAF58_7();
extern "C" void _s800CAF58_8();
extern "C" void _s800CAF58_9();
extern "C" void _s800CAF58_10();
extern "C" void _s800CAF58_11();
extern "C" void _s800CAF58_12();
extern "C" void _s800CAF58_13();
extern "C" void _s800CAF58_14();
extern "C" void _s800CAF58_15();
extern "C" void _s800CAF58_16();
extern "C" void _s800CAF58_17();
extern "C" void _s800CAF58_18();
extern "C" void _s800CAF58_19();
extern "C" void _s800CAF58_20();
extern "C" void _s800CAF58_21();
extern "C" void _s800CAF58_22();
extern "C" void _s800CAF58_23();

struct Neighbor {
    void ForceNewTree();
};

void Neighbor::ForceNewTree() {
}
