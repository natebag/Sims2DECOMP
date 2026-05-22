// 0x802D116C memalign (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s802D116C_0; mr 4,30; mr 5,29; li 6,0; li 7,0; bl _s802D116C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D116C_0();
extern "C" void _s802D116C_1();
extern "C" void f_802D116C() {}
