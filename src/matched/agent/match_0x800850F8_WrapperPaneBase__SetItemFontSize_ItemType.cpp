// 0x800850F8 WrapperPaneBase::SetItemFontSize(ItemType, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); fmr f31,f1; bl _s800850F8_0; mr 30,3; addi 3,30,32; stfs f31,0x34(3); bl _s800850F8_1; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s800850F8_0();
extern "C" void _s800850F8_1();
extern "C" void f_800850F8() {}
