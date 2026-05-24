// 0x80073820 SimModel::UpdateLowerBody(bool, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,5; cmpwi 4,0; beq 2f; li 4,15; li 5,0; li 6,0; bl _s80073820_0; lwz 9,0x13c(31); lwz 0,0xc8(9); cmpwi 0,0; bne 0f; mr 3,31; li 4,17; bl _s80073820_1; b 1f; 0:; mr 3,31; li 4,17; li 5,0; mr 6,30; bl _s80073820_2; 1:; addi 3,1,8; addi 4,31,104; bl _s80073820_3; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s80073820_4; lwz 9,0x13c(31); addi 3,1,8; li 4,3; lfs f1,0x100(9); bl _s80073820_5; addi 3,1,8; li 4,2; bl _s80073820_6; 2:; cmpwi 30,0; beq 3f; lis 9,-32696; mr 3,31; lbz 4,0x572f(9); bl _s80073820_7; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80073820_0();
extern "C" void _s80073820_1();
extern "C" void _s80073820_2();
extern "C" void _s80073820_3();
extern "C" void _s80073820_4();
extern "C" void _s80073820_5();
extern "C" void _s80073820_6();
extern "C" void _s80073820_7();

struct SimModel {
    void UpdateLowerBody();
};

void SimModel::UpdateLowerBody() {
}
