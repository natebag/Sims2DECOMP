// 0x80084914 IconItem::Startup(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x30(3)"
extern "C" void f_80084914() {}
