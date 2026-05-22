// 0x80088348 WrapperPaneBase::GetButtonPosY(WrapperPaneBase::ButtonType) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,64; rlwinm 4,4,2,0,29; lwzx 11,3,4; lwz 9,0x1c(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80088348() {}
