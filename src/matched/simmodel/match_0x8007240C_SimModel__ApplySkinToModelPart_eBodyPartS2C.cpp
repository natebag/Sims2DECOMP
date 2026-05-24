// 0x8007240C SimModel::ApplySkinToModelPart(eBodyPartS2C) (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 31,3; mr 29,4; rlwinm 11,29,2,0,29; addi 9,31,104; lwzx 0,9,11; cmpwi 0,0; beq 8f; lwzx 0,11,31; andi. 9,0,4; bne 8f; andi. 9,0,8; bne 8f; mulli 11,29,10; lis 9,-32696; addi 9,9,22168; li 28,0; li 26,1; cmpwi 29,12; add 11,11,9; lbz 27,0x1(11); beq 2f; bgt 0f; cmpwi 29,6; bgt 5f; cmpwi 29,2; blt 5f; lwz 9,0x13c(31); lis 28,22156; ori 28,28,41803; lwz 0,0x84(9); cmpwi 0,0; beq 5f; lis 28,30125; ori 28,28,9231; b 5f; 0:; cmpwi 29,13; beq 3f; cmpwi 29,19; bgt 5f; cmpwi 29,18; blt 5f; lwz 9,0x13c(31); lis 28,19656; ori 28,28,4469; lwz 0,0x84(9); cmpwi 0,0; beq 1f; lis 28,-19416; ori 28,28,60034; 1:; li 26,2; b 5f; 2:; lwz 4,0x13c(31); addi 3,1,8; li 5,12; bl _s8007240C_0; lwz 3,0x13c(31); li 4,12; lwz 30,0x138(31); bl _s8007240C_1; mr 4,3; lwz 5,0xc(1); mr 3,30; bl _s8007240C_2; b 4f; 3:; lwz 4,0x13c(31); addi 3,1,8; li 5,13; bl _s8007240C_3; lwz 3,0x13c(31); li 4,13; lwz 30,0x138(31); bl _s8007240C_4; mr 4,3; lwz 5,0x10(1); mr 3,30; bl _s8007240C_5; 4:; cmpwi 3,0; beq 5f; li 27,2; 5:; rlwinm 0,29,2,0,29; rlwinm 11,27,2,0,29; addi 9,31,104; addi 6,31,320; mr 30,0; lwzx 3,9,0; lwzx 4,6,11; cmpwi 28,0; beq 6f; mulli 9,26,10; lis 11,-32696; addi 11,11,22168; add 9,9,11; lbz 0,0x1(9); rlwinm 0,0,2,0,29; lwzx 6,6,0; b 7f; 6:; li 6,0; 7:; mr 5,28; bl _s8007240C_6; mr 4,29; mr 3,31; bl _s8007240C_7; lwzx 0,30,31; ori 0,0,8; stwx 0,30,31; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s8007240C_0();
extern "C" void _s8007240C_1();
extern "C" void _s8007240C_2();
extern "C" void _s8007240C_3();
extern "C" void _s8007240C_4();
extern "C" void _s8007240C_5();
extern "C" void _s8007240C_6();
extern "C" void _s8007240C_7();

struct SimModel {
    void ApplySkinToModelPart_eBodyPartS2C();
};

void SimModel::ApplySkinToModelPart_eBodyPartS2C() {
}
