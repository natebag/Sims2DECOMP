// 0x802D7B44 ESleep::ESleep(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 29,30,24; bl _s802D7B44_0; li 5,0; li 4,1; mr 3,30; bl _s802D7B44_1; mr 3,29; bl _s802D7B44_2; mr 3,29; mr 4,30; bl _s802D7B44_3; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D7B44_0();
extern "C" void _s802D7B44_1();
extern "C" void _s802D7B44_2();
extern "C" void _s802D7B44_3();
extern "C" void f_802D7B44() {}
