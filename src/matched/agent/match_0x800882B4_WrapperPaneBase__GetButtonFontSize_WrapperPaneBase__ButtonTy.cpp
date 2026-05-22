// 0x800882B4 WrapperPaneBase::GetButtonFontSize(WrapperPaneBase::ButtonType) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,64; lwzx 9,3,4; lfs f1,0x54(9)"
extern "C" float f_800882B4() {}
