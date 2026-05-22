// 0x80322280 HDDThread::StopAll(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; stw 0,0x5c4(3); stw 0,0x5c0(3); stw 0,0x5c8(3); stw 0,0x5cc(3); bl _s80322280_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80322280_0();
extern "C" void f_80322280() {}
