// 0x800850B0 WrapperPaneBase::SetItemFont(ItemType, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,6; bl _s800850B0_0; mr 30,3; addi 3,30,32; stw 29,0x30(3); bl _s800850B0_1; lwz 0,0x4(30); ori 0,0,2; stw 0,0x4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800850B0_0();
extern "C" void _s800850B0_1();
extern "C" void f_800850B0() {}
