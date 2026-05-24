// 0x80071558 SimModel::WeldSharedVertices(eBodyPartS2C, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; rlwinm 29,4,2,0,29; addi 28,31,104; mr 27,6; lwzx 3,28,29; cmpwi 3,0; beq 1f; lwz 3,0x120(3); cmpwi 3,0; beq 1f; lwzx 0,29,31; andi. 9,0,4; bne 1f; rlwinm 30,5,2,0,29; lwzx 4,28,30; cmpwi 4,0; beq 1f; lwz 4,0x120(4); cmpwi 4,0; beq 1f; lwzx 0,30,31; andi. 9,0,4; bne 1f; lis 9,-32707; lfs f1,0x5578(9); bl _s80071558_0; cmpwi 27,0; beq 0f; lwzx 9,28,29; lwz 3,0x120(9); bl _s80071558_1; lwzx 9,28,30; lwz 3,0x120(9); bl _s80071558_2; b 1f; 0:; lwzx 0,29,31; ori 0,0,2; stwx 0,29,31; lwzx 9,30,31; ori 9,9,2; stwx 9,30,31; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80071558_0();
extern "C" void _s80071558_1();
extern "C" void _s80071558_2();

struct SimModel {
    void WeldSharedVertices_eBodyPartS2C();
};

void SimModel::WeldSharedVertices_eBodyPartS2C() {
}
