// 0x80073114 SimModel::UpdateInnerLayerTorso(bool, (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,5; mr 28,6; cmpwi 4,0; li 30,0; beq 2f; addi 9,31,104; mr 29,9; lwz 9,0x24(9); cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; li 4,7; bl _s80073114_0; b 1f; 0:; mr 3,31; li 4,7; li 5,0; li 6,0; bl _s80073114_1; li 30,1; 1:; cmpwi 30,0; beq 2f; cmpwi 28,0; beq 2f; mr 4,29; addi 3,1,8; bl _s80073114_2; lwz 9,0x13c(31); addi 3,1,8; lfs f1,0x104(9); bl _s80073114_3; lwz 9,0x13c(31); addi 3,1,8; li 4,0; lfs f1,0xf8(9); bl _s80073114_4; addi 3,1,8; li 4,2; bl _s80073114_5; 2:; cmpwi 27,0; beq 3f; lis 9,-32696; mr 3,31; lbz 4,0x56df(9); bl _s80073114_6; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80073114_0();
extern "C" void _s80073114_1();
extern "C" void _s80073114_2();
extern "C" void _s80073114_3();
extern "C" void _s80073114_4();
extern "C" void _s80073114_5();
extern "C" void _s80073114_6();

struct SimModel {
    void UpdateInnerLayerTorso();
};

void SimModel::UpdateInnerLayerTorso() {
}
