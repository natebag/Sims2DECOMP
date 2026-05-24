// 0x800732CC SimModel::UpdateMidLayerTorso(bool, (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,5; mr 29,6; mr 30,7; cmpwi 4,0; beq 1f; li 4,9; li 5,0; li 6,0; bl _s800732CC_0; cmpwi 30,0; beq 0f; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s800732CC_1; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s800732CC_2; 0:; cmpwi 29,0; beq 1f; addi 4,31,104; addi 3,1,8; bl _s800732CC_3; lwz 9,0x13c(31); addi 3,1,8; lfs f1,0x104(9); bl _s800732CC_4; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s800732CC_5; addi 3,1,8; li 4,2; bl _s800732CC_6; 1:; cmpwi 28,0; beq 2f; lis 9,-32696; mr 3,31; lbz 4,0x56f3(9); bl _s800732CC_7; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800732CC_0();
extern "C" void _s800732CC_1();
extern "C" void _s800732CC_2();
extern "C" void _s800732CC_3();
extern "C" void _s800732CC_4();
extern "C" void _s800732CC_5();
extern "C" void _s800732CC_6();
extern "C" void _s800732CC_7();

struct SimModel {
    void UpdateMidLayerTorso();
};

void SimModel::UpdateMidLayerTorso() {
}
