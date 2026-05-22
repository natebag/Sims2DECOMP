// 0x8008633C WrapperPaneBase::UpdateAptButtonPosX(WrapperPaneBase::ButtonType) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,256; lwz 9,0x4(3); slw 0,0,4; and 11,9,0; beqlr; rlwinm 11,4,2,0,29; addi 9,3,64; lwzx 10,9,11; lwz 0,0x4(10); oris 0,0,4224; stw 0,0x4(10)"
extern "C" void f_8008633C() {}
