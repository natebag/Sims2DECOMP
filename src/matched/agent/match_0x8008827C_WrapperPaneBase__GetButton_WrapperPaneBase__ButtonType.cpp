// 0x8008827C WrapperPaneBase::GetButton(WrapperPaneBase::ButtonType) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,64; lwzx 3,3,4"
extern "C" int f_8008827C() {}
