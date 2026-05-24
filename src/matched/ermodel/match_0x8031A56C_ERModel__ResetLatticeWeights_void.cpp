// 0x8031A56C ERModel::ResetLatticeWeights(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; li 30,0; addi 9,29,260; lwz 0,0x4(9); cmpw 30,0; bge 3f; mr 25,9; lis 26,-32702; 0:; li 31,0; mulli 28,30,224; addi 27,30,1; b 2f; 1:; lfs f1,0x8e0(26); mr 5,31; mr 3,29; mr 4,30; bl _s8031A56C_0; addi 31,31,1; 2:; lwz 3,0x104(29); add 3,3,28; bl _s8031A56C_1; cmpw 31,3; blt 1b; lwz 0,0x4(25); mr 30,27; cmpw 30,0; blt 0b; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8031A56C_0();
extern "C" void _s8031A56C_1();

struct ERModel {
    void ResetLatticeWeights();
};

void ERModel::ResetLatticeWeights() {
}
