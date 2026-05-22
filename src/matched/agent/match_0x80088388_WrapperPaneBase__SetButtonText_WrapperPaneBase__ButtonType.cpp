// 0x80088388 WrapperPaneBase::SetButtonText(WrapperPaneBase::ButtonType, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; rlwinm 0,29,2,0,29; addi 9,30,64; lwzx 3,9,0; mr 4,5; bl _s80088388_0; mr 3,30; mr 4,29; bl _s80088388_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80088388_0();
extern "C" void _s80088388_1();
extern "C" void f_80088388() {}
