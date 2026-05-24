// 0x8022BD74 EIStaticModel::DeallocateModel(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x120(31); cmpwi 3,0; beq 0f; bl _s8022BD74_0; li 0,0; stw 0,0x120(31); 0:; lwz 0,0x11c(31); li 30,0; cmpw 30,0; bge 2f; li 29,0; 1:; lwz 9,0x118(31); addi 30,30,1; add 9,29,9; lwz 3,0x4(9); addi 29,29,16; bl _s8022BD74_1; lwz 0,0x11c(31); cmpw 30,0; blt 1b; 2:; li 30,0; stw 30,0x11c(31); bl _s8022BD74_2; lwz 4,0x118(31); bl _s8022BD74_3; stw 30,0x114(31); stw 30,0x118(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8022BD74_0();
extern "C" void _s8022BD74_1();
extern "C" void _s8022BD74_2();
extern "C" void _s8022BD74_3();

struct EIStaticModel {
    void DeallocateModel();
};

void EIStaticModel::DeallocateModel() {
}
