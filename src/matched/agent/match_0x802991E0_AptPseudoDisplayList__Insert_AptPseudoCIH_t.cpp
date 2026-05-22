// 0x802991E0 AptPseudoDisplayList::Insert(AptPseudoCIH_t (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; mr 30,5; mr. 4,6; beq 0f; bl _s802991E0_0; mr 3,31; mr 4,30; mr 5,29; bl _s802991E0_1; b 1f; 0:; mr 3,31; mr 4,30; mr 5,29; bl _s802991E0_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802991E0_0();
extern "C" void _s802991E0_1();
extern "C" void _s802991E0_2();
extern "C" void f_802991E0() {}
