// 0x800EA98C cXObject::setObjectImpl(cXObjectImpl (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); stw 4,0x0(9)"
extern "C" void f_800EA98C() {}
