// 0x801F4FCC INVTarget::SetOnMsgInvCurrentPanel(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 3,4; bl _s801F4FCC_0; xori 3,3,1; subfic 0,3,0; adde 3,0,3; stw 3,0x3198(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F4FCC_0();
extern "C" void f_801F4FCC() {}
