// 0x80085254 WrapperPaneBase::SetItemSize(ItemType, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,6; bl _s80085254_0; lwz 9,0x1c(3); mr 4,30; lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80085254_0();
extern "C" void f_80085254() {}
