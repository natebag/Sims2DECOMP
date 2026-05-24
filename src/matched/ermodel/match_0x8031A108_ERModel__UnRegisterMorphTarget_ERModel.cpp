// 0x8031A108 ERModel::UnRegisterMorphTarget(ERModel (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 11,4; beq 3f; addi 9,3,156; li 4,0; lwzx 0,9,4; mr 8,9; li 10,0; cmpw 11,0; b 1f; 0:; addi 4,4,1; cmpwi 4,11; bgt 2f; rlwinm 0,4,2,0,29; lwzx 9,8,0; cmpw 11,9; 1:; bne 0b; li 10,1; 2:; cmpwi 10,0; beq 3f; bl _s8031A108_0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8031A108_0();

struct ERModel {
    void UnRegisterMorphTarget_ERModel();
};

void ERModel::UnRegisterMorphTarget_ERModel() {
}
