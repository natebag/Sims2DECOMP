// 0x80070FB4 SimModel::UpdateModelPart(eBodyPartS2C, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 29,3; mr 30,4; mr 26,5; lwz 4,0x13c(29); mr 27,6; addi 3,1,8; mr 5,30; bl _s80070FB4_0; lwz 3,0x13c(29); mr 4,30; lwz 28,0x138(29); bl _s80070FB4_1; mr 5,3; mr 4,30; addi 6,1,8; mr 3,28; bl _s80070FB4_2; mr 5,3; mr 4,30; mr 3,29; mr 6,26; mr 7,27; bl _s80070FB4_3; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s80070FB4_0();
extern "C" void _s80070FB4_1();
extern "C" void _s80070FB4_2();
extern "C" void _s80070FB4_3();

struct SimModel {
    void UpdateModelPart_eBodyPartS2C();
};

void SimModel::UpdateModelPart_eBodyPartS2C() {
}
