// 0x80085514 WrapperPaneBase::GetItemSizeY(ItemType, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80085514_0; lwz 9,0x1c(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80085514_0();
extern "C" void f_80085514() {}
