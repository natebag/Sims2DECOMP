// 0x80388A3C GXSaveCPUFifo (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80388A3C_0; mr 3,31; bl _s80388A3C_1; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80388A3C_0();
extern "C" void _s80388A3C_1();
extern "C" void f_80388A3C() {}
