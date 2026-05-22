// 0x800888E0 WrapperPaneBase::SetDeclinePosX(float) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 11,0x44(30); lwz 9,0x1c(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; li 4,1; bl _s800888E0_0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800888E0_0();
extern "C" void f_800888E0() {}
