// 0x802E1E54 BackgroundImpl::ExecuteRoutine(void (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; li 3,16; bl _s802E1E54_0; mr 4,3; li 0,0; li 9,3; stw 0,0xc(4); stw 9,0x0(4); mr 3,30; stw 29,0x4(4); bl _s802E1E54_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E1E54_0();
extern "C" void _s802E1E54_1();
extern "C" void f_802E1E54() {}
