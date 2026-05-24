// 0x8031A21C ERModel::MorphTargets(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 0,0xfc(31); li 3,0; cmpwi 0,0; beq 2f; addi 9,31,60; li 29,0; lwz 0,0x4(9); mr 28,9; cmpw 3,0; bge 2f; li 30,0; 0:; lwz 3,0x3c(31); addi 4,31,204; add 3,3,30; bl _s8031A21C_0; mr. 3,3; bne 1f; li 3,0; b 2f; 1:; lwz 0,0x4(28); addi 29,29,1; addi 30,30,24; cmpw 29,0; blt 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8031A21C_0();

struct ERModel {
    void MorphTargets();
};

void ERModel::MorphTargets() {
}
