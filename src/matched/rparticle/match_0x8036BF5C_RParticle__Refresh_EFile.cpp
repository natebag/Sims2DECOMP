// 0x8036BF5C RParticle::Refresh(EFile (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 29,3; mr. 31,4; beq 4f; addi 3,1,8; lwz 28,0x14(29); bl _s8036BF5C_0; lis 5,20545; addi 3,1,8; mr 4,31; ori 5,5,21076; li 6,14; li 7,14; bl _s8036BF5C_1; cmpwi 3,0; beq 0f; lwz 9,0x18(1); lwz 0,0x10(29); mr 5,9; lwz 4,0x14(29); rlwimi 0,9,8,0,23; stw 0,0x10(29); lwz 9,0x28(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,0x28(31); addi 4,1,32; li 5,20; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; bl _s8036BF5C_2; lwz 4,0x30(1); li 5,0; bl _s8036BF5C_3; lwz 9,0x28(31); mr 30,3; lwz 5,0x30(1); mr 4,30; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; bl _s8036BF5C_4; lwz 5,0x30(1); addi 3,3,1; lwz 0,0x10(29); add 4,30,3; subf 5,3,5; rlwimi 0,5,8,0,23; lwz 3,0x14(29); stw 0,0x10(29); bl _s8036BF5C_5; bl _s8036BF5C_6; mr 4,30; bl _s8036BF5C_7; 1:; lwz 0,0x18(29); li 10,0; cmpw 10,0; bge 3f; addi 11,28,364; addi 9,29,28; 2:; lwz 0,0x0(9); addi 10,10,1; addi 9,9,4; stw 0,0x0(11); addi 11,11,132; lwz 0,0x18(29); cmpw 10,0; blt 2b; 3:; addi 3,1,8; li 4,2; bl _s8036BF5C_8; 4:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"

extern "C" void _s8036BF5C_0();
extern "C" void _s8036BF5C_1();
extern "C" void _s8036BF5C_2();
extern "C" void _s8036BF5C_3();
extern "C" void _s8036BF5C_4();
extern "C" void _s8036BF5C_5();
extern "C" void _s8036BF5C_6();
extern "C" void _s8036BF5C_7();
extern "C" void _s8036BF5C_8();

struct RParticle {
    void Refresh_EFile();
};

void RParticle::Refresh_EFile() {
}
