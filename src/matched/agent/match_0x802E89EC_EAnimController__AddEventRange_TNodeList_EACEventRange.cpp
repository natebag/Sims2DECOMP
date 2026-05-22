// 0x802E89EC EAnimController::AddEventRange(TNodeList<EACEventRange (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f30,0x10(1); stfd f31,0x18(1); stmw 30,0x8(1); stw 0,0x24(1); mr 30,3; mr 31,4; fmr f31,f1; li 3,12; fmr f30,f2; bl _s802E89EC_0; mr. 9,3; beq 0f; stw 31,0x0(9); mr 3,30; stfs f31,0x4(9); mr 4,9; stfs f30,0x8(9); bl _s802E89EC_1; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x8(1); lfd f30,0x10(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802E89EC_0();
extern "C" void _s802E89EC_1();
extern "C" void f_802E89EC() {}
