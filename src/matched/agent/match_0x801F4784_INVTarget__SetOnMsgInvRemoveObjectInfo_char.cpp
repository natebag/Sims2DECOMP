// 0x801F4784 INVTarget::SetOnMsgInvRemoveObjectInfo(char (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x88(3); li 3,1"
extern "C" void f_801F4784() {}
