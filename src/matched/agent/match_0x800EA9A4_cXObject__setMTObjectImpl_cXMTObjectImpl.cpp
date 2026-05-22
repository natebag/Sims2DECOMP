// 0x800EA9A4 cXObject::setMTObjectImpl(cXMTObjectImpl (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); stw 4,0x8(9)"
extern "C" void f_800EA9A4() {}
