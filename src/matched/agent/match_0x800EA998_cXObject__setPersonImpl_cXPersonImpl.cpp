// 0x800EA998 cXObject::setPersonImpl(cXPersonImpl (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); stw 4,0x4(9)"
extern "C" void f_800EA998() {}
