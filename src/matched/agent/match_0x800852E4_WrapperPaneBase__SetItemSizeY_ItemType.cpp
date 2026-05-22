// 0x800852E4 WrapperPaneBase::SetItemSizeY(ItemType, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stfd f31,0x8(1); stw 0,0x14(1); fmr f31,f1; bl _s800852E4_0; lwz 9,0x1c(3); fmr f1,f31; lha 0,0x88(9); lwz 9,0x8c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; lfd f31,0x8(1); addi 1,1,16"
extern "C" void _s800852E4_0();
extern "C" void f_800852E4() {}
