// 0x800880B4 WrapperPaneBase::SetMenuItemPosY(int, (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 5,4; li 4,1; bl _s800880B4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800880B4_0();
extern "C" void f_800880B4() {}
