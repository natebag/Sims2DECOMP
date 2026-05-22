// 0x803103C8 EResourceLoaderImpl::TerminateThread(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 3,40; bl _s803103C8_0; bl _s803103C8_1; mr 4,3; li 0,2; stw 0,0x0(4); mr 3,30; bl _s803103C8_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803103C8_0();
extern "C" void _s803103C8_1();
extern "C" void _s803103C8_2();
extern "C" void f_803103C8() {}
