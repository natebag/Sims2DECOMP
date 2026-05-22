// 0x802E1EA8 BackgroundImpl::ExecuteArgRoutine(void (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; li 3,16; bl _s802E1EA8_0; mr 9,3; li 0,4; stw 0,0x0(9); mr 3,30; stw 29,0x4(9); mr 4,9; stw 28,0xc(9); bl _s802E1EA8_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802E1EA8_0();
extern "C" void _s802E1EA8_1();
extern "C" void f_802E1EA8() {}
