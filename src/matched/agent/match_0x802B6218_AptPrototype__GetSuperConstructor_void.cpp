// 0x802B6218 AptPrototype::GetSuperConstructor(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x20(3)"
extern "C" int f_802B6218() {}
