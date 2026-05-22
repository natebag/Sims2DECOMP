// 0x802B5124 AptValueFactory::CreateUndefined(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-22936(13)"
extern "C" int f_802B5124() {}
