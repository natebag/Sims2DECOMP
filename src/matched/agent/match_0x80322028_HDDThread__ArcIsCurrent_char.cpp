// 0x80322028 HDDThread::ArcIsCurrent(char (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80322028_0; mr 4,3; mr 3,30; bl _s80322028_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80322028_0();
extern "C" void _s80322028_1();
extern "C" void f_80322028() {}
