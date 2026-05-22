// 0x800184A0 ESimsCam::CalcTranslationStiffness(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lfs f5,0x448(3); lfs f4,0x2c(9); lfs f1,0x10(9); lfs f2,0x14(9); lfs f3,0x28(9); bl _s800184A0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800184A0_0();
extern "C" void f_800184A0() {}
