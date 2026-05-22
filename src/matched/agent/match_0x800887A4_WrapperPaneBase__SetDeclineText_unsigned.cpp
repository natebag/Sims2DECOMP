// 0x800887A4 WrapperPaneBase::SetDeclineText(unsigned (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,0x44(30); bl _s800887A4_0; mr 3,30; li 4,1; bl _s800887A4_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800887A4_0();
extern "C" void _s800887A4_1();
extern "C" void f_800887A4() {}
