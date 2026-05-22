// 0x800DCEC8 HierarchySite::HierarchySite(cXObjectImpl (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; li 8,1; stw 6,0x10(11); stw 4,0xc(11); lwz 9,0x0(5); lwz 10,0x4(5); stw 9,0x4(11); stw 10,0x8(11); lwz 0,0x80(4); stw 8,0x0(11); stw 0,0x14(11)"
extern "C" void f_800DCEC8() {}
