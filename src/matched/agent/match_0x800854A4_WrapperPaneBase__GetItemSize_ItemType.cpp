// 0x800854A4 WrapperPaneBase::GetItemSize(ItemType, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800854A4_0; lwz 9,0x1c(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800854A4_0();
extern "C" void f_800854A4() {}
