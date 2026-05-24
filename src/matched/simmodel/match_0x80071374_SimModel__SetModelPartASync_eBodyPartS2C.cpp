// 0x80071374 SimModel::SetModelPartASync(eBodyPartS2C, (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; rlwinm 0,30,2,0,29; addi 9,31,104; lwzx 9,9,0; mr 29,5; li 28,0; cmpwi 9,0; beq 1f; lwz 9,0x120(9); cmpwi 9,0; beq 0f; lwz 0,0x8(9); cmpw 29,0; bne 0f; li 3,0; b 3f; 0:; li 28,1; 1:; mr 3,31; mr 4,30; bl _s80071374_0; rlwinm 11,30,2,0,29; cmpwi 29,0; lwzx 0,11,31; rlwinm 0,0,0,31,27; stwx 0,11,31; beq 2f; addi 9,31,208; lis 3,-32692; stwx 29,9,11; addi 3,3,-27556; mr 4,29; lwzx 0,11,31; ori 0,0,32; stwx 0,11,31; bl _s80071374_1; li 3,1; b 3f; 2:; mr 3,28; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80071374_0();
extern "C" void _s80071374_1();

struct SimModel {
    void SetModelPartASync_eBodyPartS2C();
};

void SimModel::SetModelPartASync_eBodyPartS2C() {
}
