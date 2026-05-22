// 0x8008520C WrapperPaneBase::SetItemPosY(ItemType, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stfd f31,0x8(1); stw 0,0x14(1); fmr f31,f1; bl _s8008520C_0; lwz 9,0x1c(3); fmr f1,f31; lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; lfd f31,0x8(1); addi 1,1,16"
extern "C" void _s8008520C_0();
extern "C" void f_8008520C() {}
