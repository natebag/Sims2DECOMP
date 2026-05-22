// 0x8026BE2C AptNonGCFreeSavedSize(void (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwzu 5,-4(3); mr 4,3; addi 5,5,4; lwz 3,-23020(13); bl _s8026BE2C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026BE2C_0();
extern "C" void f_8026BE2C() {}
