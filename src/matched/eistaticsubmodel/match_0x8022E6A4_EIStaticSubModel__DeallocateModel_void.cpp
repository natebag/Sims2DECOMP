// 0x8022E6A4 EIStaticSubModel::DeallocateModel(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 3,0xa0(31); cmpwi 3,0; beq 0f; bl _s8022E6A4_0; li 0,0; stw 0,0xa0(31); 0:; lwz 0,0x9c(31); li 30,0; cmpw 30,0; bge 2f; li 29,0; 1:; lwz 9,0x98(31); addi 30,30,1; add 9,29,9; lwz 3,0x4(9); addi 29,29,16; bl _s8022E6A4_1; lwz 0,0x9c(31); cmpw 30,0; blt 1b; 2:; li 30,0; stw 30,0x9c(31); bl _s8022E6A4_2; lwz 4,0x98(31); bl _s8022E6A4_3; stw 30,0x94(31); stw 30,0x98(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8022E6A4_0();
extern "C" void _s8022E6A4_1();
extern "C" void _s8022E6A4_2();
extern "C" void _s8022E6A4_3();

struct EIStaticSubModel {
    void DeallocateModel();
};

void EIStaticSubModel::DeallocateModel() {
}
