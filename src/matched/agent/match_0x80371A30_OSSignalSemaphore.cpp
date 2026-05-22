// 0x80371A30 OSSignalSemaphore (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s80371A30_0; lwz 30,0x0(29); addi 31,3,0; addi 3,29,4; addi 0,30,1; stw 0,0x0(29); bl _s80371A30_1; mr 3,31; bl _s80371A30_2; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80371A30_0();
extern "C" void _s80371A30_1();
extern "C" void _s80371A30_2();
extern "C" void f_80371A30() {}
