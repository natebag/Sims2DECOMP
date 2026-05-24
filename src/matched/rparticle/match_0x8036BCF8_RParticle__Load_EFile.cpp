// 0x8036BCF8 RParticle::Load(EFile (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 25,0x3c(1); stw 0,0x5c(1); mr 29,3; mr 31,4; bl _s8036BCF8_0; lis 3,-32692; li 4,1420; li 5,16; addi 3,3,6092; bl _s8036BCF8_1; mr 0,3; li 4,0; li 5,1420; stw 0,0x14(29); bl _s8036BCF8_2; addi 3,1,8; bl _s8036BCF8_3; lis 5,20545; addi 3,1,8; mr 4,31; ori 5,5,21076; li 6,14; li 7,14; bl _s8036BCF8_4; cmpwi 3,0; beq 0f; addi 3,1,8; bl _s8036BCF8_5; lwz 9,0x18(1); lwz 0,0x10(29); mr 5,9; lwz 4,0x14(29); rlwimi 0,9,8,0,23; stw 0,0x10(29); lwz 9,0x28(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,0x28(31); addi 4,1,32; li 5,20; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; bl _s8036BCF8_6; lwz 4,0x30(1); li 5,0; bl _s8036BCF8_7; lwz 9,0x28(31); mr 30,3; lwz 5,0x30(1); mr 4,30; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; bl _s8036BCF8_8; lwz 5,0x30(1); addi 3,3,1; lwz 0,0x10(29); add 4,30,3; subf 5,3,5; rlwimi 0,5,8,0,23; lwz 3,0x14(29); stw 0,0x10(29); bl _s8036BCF8_9; bl _s8036BCF8_10; mr 4,30; bl _s8036BCF8_11; 1:; lwz 28,0x14(29); lwz 0,0x108(28); andis. 9,0,32; beq 2f; li 0,1; addi 31,28,220; stw 0,0x18(29); mr 3,31; bl _s8036BCF8_12; mr. 4,3; beq 7f; lis 3,-32692; li 5,0; addi 3,3,-27556; b 6f; 2:; andis. 9,0,512; beq 5f; lwz 9,0x168(28); li 27,0; stw 9,0x18(29); lwz 0,0x168(28); cmpw 27,0; bge 9f; lis 25,-32692; li 26,0; addi 31,29,28; addi 30,28,364; 3:; mr 3,30; bl _s8036BCF8_13; mr. 3,3; beq 4f; mr 4,3; li 5,0; addi 3,25,-27556; li 6,0; bl _s8036BCF8_14; 4:; stw 3,0x0(31); addi 9,29,28; lwzx 0,9,26; addi 27,27,1; addi 26,26,4; addi 31,31,4; stw 0,0x0(30); addi 30,30,132; lwz 0,0x168(28); cmpw 27,0; blt 3b; b 9f; 5:; li 0,1; addi 31,28,220; stw 0,0x18(29); mr 3,31; bl _s8036BCF8_15; mr. 4,3; beq 7f; lis 3,-32692; li 5,0; addi 3,3,-17444; 6:; li 6,0; bl _s8036BCF8_16; stw 3,0x1c(29); b 8f; 7:; stw 4,0x1c(29); 8:; lwz 0,0x1c(29); stw 0,0x0(31); lwz 9,0x1c(29); stw 9,0x16c(28); 9:; addi 3,1,8; li 4,2; bl _s8036BCF8_17; lwz 0,0x5c(1); mtspr 8,0; lmw 25,0x3c(1); addi 1,1,88"

extern "C" void _s8036BCF8_0();
extern "C" void _s8036BCF8_1();
extern "C" void _s8036BCF8_2();
extern "C" void _s8036BCF8_3();
extern "C" void _s8036BCF8_4();
extern "C" void _s8036BCF8_5();
extern "C" void _s8036BCF8_6();
extern "C" void _s8036BCF8_7();
extern "C" void _s8036BCF8_8();
extern "C" void _s8036BCF8_9();
extern "C" void _s8036BCF8_10();
extern "C" void _s8036BCF8_11();
extern "C" void _s8036BCF8_12();
extern "C" void _s8036BCF8_13();
extern "C" void _s8036BCF8_14();
extern "C" void _s8036BCF8_15();
extern "C" void _s8036BCF8_16();
extern "C" void _s8036BCF8_17();

struct RParticle {
    void Load_EFile();
};

void RParticle::Load_EFile() {
}
