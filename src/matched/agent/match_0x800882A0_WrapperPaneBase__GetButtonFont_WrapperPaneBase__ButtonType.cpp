// 0x800882A0 WrapperPaneBase::GetButtonFont(WrapperPaneBase::ButtonType) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,64; rlwinm 4,4,2,0,29; lwzx 9,3,4; lwz 3,0x50(9)"
extern "C" int f_800882A0() {}
