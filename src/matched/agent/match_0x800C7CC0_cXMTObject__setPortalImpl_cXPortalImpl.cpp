// 0x800C7CC0 cXMTObject::setPortalImpl(cXPortalImpl (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 11,0x0(9); stw 4,0xc(11)"
extern "C" void f_800C7CC0() {}
