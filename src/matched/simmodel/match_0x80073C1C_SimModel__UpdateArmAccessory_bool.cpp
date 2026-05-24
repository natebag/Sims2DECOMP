// 0x80073C1C SimModel::UpdateArmAccessory(bool, (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,5; mr 29,6; cmpwi 4,0; beq 3f; lwz 11,0x13c(31); li 30,1; lwz 0,0xb0(11); cmpwi 0,3; bne 0f; lwz 9,0x94(31); cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; lbz 5,0xa4(11); li 4,11; lwz 3,0x138(31); extsb 5,5; bl _s80073C1C_0; cmpwi 3,0; bne 0f; li 30,0; 0:; lwz 11,0x13c(31); lwz 0,0xc0(11); cmpwi 0,3; bne 1f; lwz 9,0xa0(31); cmpwi 9,0; beq 1f; lwz 0,0x120(9); cmpwi 0,0; beq 1f; lbz 5,0xb4(11); li 4,14; lwz 3,0x138(31); extsb 5,5; bl _s80073C1C_1; cmpwi 3,0; bne 1f; li 30,0; 1:; cmpwi 30,0; beq 2f; mr 3,31; li 4,21; li 5,0; li 6,0; bl _s80073C1C_2; cmpwi 29,0; beq 3f; addi 4,31,104; addi 3,1,8; bl _s80073C1C_3; lwz 9,0x13c(31); addi 3,1,8; li 4,1; lfs f1,0xfc(9); bl _s80073C1C_4; addi 3,1,8; li 4,2; bl _s80073C1C_5; b 3f; 2:; mr 3,31; li 4,21; bl _s80073C1C_6; 3:; cmpwi 28,0; beq 4f; lis 9,-32696; mr 3,31; lbz 4,0x576b(9); bl _s80073C1C_7; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s80073C1C_0();
extern "C" void _s80073C1C_1();
extern "C" void _s80073C1C_2();
extern "C" void _s80073C1C_3();
extern "C" void _s80073C1C_4();
extern "C" void _s80073C1C_5();
extern "C" void _s80073C1C_6();
extern "C" void _s80073C1C_7();

struct SimModel {
    void UpdateArmAccessory();
};

void SimModel::UpdateArmAccessory() {
}
