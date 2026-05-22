// 0x80321F54 HDDThread::DoFormat(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80321F54_0; li 0,1; stw 0,0x5c0(30); stw 0,0x5c8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80321F54_0();
extern "C" void f_80321F54() {}
