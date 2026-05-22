// 0x801F677C INVTarget::GetOnMsgInvCurrentCell(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x84(3); addi 9,13,-28700; mr 3,4; rlwinm 0,0,2,0,29; lis 4,-32704; lwzx 5,9,0; addi 4,4,-30836; crxor 6,6,6; bl _s801F677C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801F677C_0();
extern "C" void f_801F677C() {}
