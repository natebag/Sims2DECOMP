// 0x802E39F0 main (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s802E39F0_0; mr 4,30; mr 3,29; bl _s802E39F0_1; bl _s802E39F0_2; li 3,0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802E39F0_0();
extern "C" void _s802E39F0_1();
extern "C" void _s802E39F0_2();
extern "C" void f_802E39F0() {}
