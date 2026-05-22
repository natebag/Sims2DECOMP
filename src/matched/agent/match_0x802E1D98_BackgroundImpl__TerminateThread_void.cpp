// 0x802E1D98 BackgroundImpl::TerminateThread(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 3,16; bl _s802E1D98_0; mr 4,3; li 0,0; li 9,2; stw 0,0xc(4); stw 9,0x0(4); mr 3,30; bl _s802E1D98_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E1D98_0();
extern "C" void _s802E1D98_1();
extern "C" void f_802E1D98() {}
