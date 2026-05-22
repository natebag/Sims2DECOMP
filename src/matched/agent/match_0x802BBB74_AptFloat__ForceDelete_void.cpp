// 0x802BBB74 AptFloat::ForceDelete(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26912(13); stw 0,0xc(3); stw 3,-26912(13)"
extern "C" void f_802BBB74() {}
