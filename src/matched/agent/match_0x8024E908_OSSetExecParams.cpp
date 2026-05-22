// 0x8024E908 __OSSetExecParams (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 0,3; mr 31,4; mr 3,31; mr 4,0; li 5,28; bl _s8024E908_0; lis 3,-32768; stw 31,0x30f0(3); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8024E908_0();
extern "C" void f_8024E908() {}
