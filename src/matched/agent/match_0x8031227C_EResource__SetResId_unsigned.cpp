// 0x8031227C EResource::SetResId(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x8(3)"
extern "C" void f_8031227C() {}
