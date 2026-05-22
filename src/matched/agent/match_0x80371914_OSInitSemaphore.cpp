// 0x80371914 OSInitSemaphore (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; bl _s80371914_0; addi 31,3,0; addi 3,29,4; bl _s80371914_1; stw 30,0x0(29); mr 3,31; bl _s80371914_2; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80371914_0();
extern "C" void _s80371914_1();
extern "C" void _s80371914_2();
extern "C" void f_80371914() {}
