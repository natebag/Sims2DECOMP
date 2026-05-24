// 0x8031A2A4 ERModel::MorphLattices(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; lwz 0,0xfc(29); cmpwi 0,0; beq 3f; addi 9,29,260; li 31,0; lwz 0,0x4(9); mr 27,9; addi 28,29,60; cmpw 31,0; bge 1f; li 30,0; 0:; lwz 3,0x104(29); addi 31,31,1; add 3,3,30; bl _s8031A2A4_0; addi 30,30,224; lwz 0,0x4(27); cmpw 31,0; blt 0b; 1:; lwz 0,0x4(28); li 31,0; cmpw 31,0; bge 3f; li 30,0; 2:; lwz 3,0x3c(29); addi 31,31,1; add 3,3,30; bl _s8031A2A4_1; addi 30,30,24; lwz 0,0x4(28); cmpw 31,0; blt 2b; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8031A2A4_0();
extern "C" void _s8031A2A4_1();

struct ERModel {
    void MorphLattices();
};

void ERModel::MorphLattices() {
}
