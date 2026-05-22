// 0x800878B4 IconItem::SetShader(ERShader (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x30(3)"
extern "C" void f_800878B4() {}
