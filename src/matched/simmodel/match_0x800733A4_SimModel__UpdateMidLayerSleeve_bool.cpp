// 0x800733A4 SimModel::UpdateMidLayerSleeve(bool, (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 31,3; mr 28,5; mr 26,6; mr 30,7; cmpwi 4,0; li 27,0; beq 2f; addi 9,31,104; mr 29,9; lwz 9,0x38(9); cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; li 4,11; bl _s800733A4_0; b 1f; 0:; mr 3,31; li 4,11; li 5,0; mr 6,28; bl _s800733A4_1; li 27,1; cmpwi 30,0; beq 1f; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s800733A4_2; mr 3,31; li 4,1; li 5,0; li 6,0; bl _s800733A4_3; 1:; cmpwi 27,0; beq 2f; cmpwi 26,0; beq 2f; mr 4,29; addi 3,1,8; bl _s800733A4_4; lwz 9,0x13c(31); addi 3,1,8; li 4,1; lfs f1,0xfc(9); bl _s800733A4_5; addi 3,1,8; li 4,2; bl _s800733A4_6; 2:; cmpwi 28,0; beq 3f; lis 9,-32696; mr 3,31; lbz 4,0x5707(9); bl _s800733A4_7; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

extern "C" void _s800733A4_0();
extern "C" void _s800733A4_1();
extern "C" void _s800733A4_2();
extern "C" void _s800733A4_3();
extern "C" void _s800733A4_4();
extern "C" void _s800733A4_5();
extern "C" void _s800733A4_6();
extern "C" void _s800733A4_7();

struct SimModel {
    void UpdateMidLayerSleeve();
};

void SimModel::UpdateMidLayerSleeve() {
}
