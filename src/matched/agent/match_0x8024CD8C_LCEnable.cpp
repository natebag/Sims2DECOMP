// 0x8024CD8C LCEnable (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s8024CD8C_0; mr 31,3; bl _s8024CD8C_1; mr 3,31; bl _s8024CD8C_2; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8024CD8C_0();
extern "C" void _s8024CD8C_1();
extern "C" void _s8024CD8C_2();
extern "C" void f_8024CD8C() {}
