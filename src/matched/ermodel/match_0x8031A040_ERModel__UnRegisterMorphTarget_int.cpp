// 0x8031A040 ERModel::UnRegisterMorphTarget(int) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 29,3; mr 27,4; rlwinm 11,27,2,0,29; addi 10,29,156; lwzx 3,10,11; cmpwi 3,0; beq 3f; lha 0,0xc(3); cmpwi 0,0; ble 3f; lha 0,0xc(3); cmpwi 0,1; bne 2f; addi 9,29,60; li 30,0; lwz 0,0x4(9); mr 26,9; mr 28,11; mr 25,10; cmpw 30,0; addi 24,29,204; bge 1f; li 31,0; 0:; lwz 3,0x3c(29); mr 4,27; addi 30,30,1; add 3,3,31; bl _s8031A040_0; addi 31,31,24; lwz 0,0x4(26); cmpw 30,0; blt 0b; 1:; lwzx 3,25,28; bl _s8031A040_1; lis 9,-32702; li 0,0; lfs f0,0x8dc(9); stwx 0,25,28; stfsx f0,24,28; b 3f; 2:; bl _s8031A040_2; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s8031A040_0();
extern "C" void _s8031A040_1();
extern "C" void _s8031A040_2();

struct ERModel {
    void UnRegisterMorphTarget();
};

void ERModel::UnRegisterMorphTarget() {
}
