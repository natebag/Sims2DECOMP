// 0x8008546C WrapperPaneBase::GetItemPosY(ItemType, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8008546C_0; lwz 9,0x1c(3); lha 0,0x60(9); lwz 9,0x64(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8008546C_0();
extern "C" void f_8008546C() {}
