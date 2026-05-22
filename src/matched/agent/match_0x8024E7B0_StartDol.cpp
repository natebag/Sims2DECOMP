// 0x8024E7B0 StartDol (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; mr 31,4; li 3,28; li 4,1; bl _s8024E7B0_0; mr 4,3; mr 3,30; bl _s8024E7B0_1; lis 3,-13312; addi 3,3,12288; li 0,7; stw 0,0x24(3); bl _s8024E7B0_2; mr 3,31; bl _s8024E7B0_3; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8024E7B0_0();
extern "C" void _s8024E7B0_1();
extern "C" void _s8024E7B0_2();
extern "C" void _s8024E7B0_3();
extern "C" void f_8024E7B0() {}
