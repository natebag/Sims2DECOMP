// 0x801A0808 CASTarget::GetCurPartUIFocus(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xa4(3)"
extern "C" int f_801A0808() {}
