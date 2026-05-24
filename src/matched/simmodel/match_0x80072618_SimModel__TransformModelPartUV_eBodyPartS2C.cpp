// 0x80072618 SimModel::TransformModelPartUV(eBodyPartS2C) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); rlwinm 27,4,2,0,29; addi 31,3,104; lwzx 9,31,27; cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; addi 30,1,16; addi 29,1,24; addi 28,1,32; li 0,0; mr 9,28; addi 5,1,8; mr 6,30; addi 7,1,40; mr 8,29; stw 0,0x28(1); bl _s80072618_0; lwzx 9,31,27; mr 5,30; lwz 6,0x28(1); mr 7,29; lwz 3,0x120(9); mr 8,28; addi 4,1,8; bl _s80072618_1; 0:; lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"

extern "C" void _s80072618_0();
extern "C" void _s80072618_1();

struct SimModel {
    void TransformModelPartUV_eBodyPartS2C();
};

void SimModel::TransformModelPartUV_eBodyPartS2C() {
}
