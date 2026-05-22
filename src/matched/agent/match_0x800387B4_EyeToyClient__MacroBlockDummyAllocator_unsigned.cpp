// 0x800387B4 EyeToyClient::MacroBlockDummyAllocator(unsigned (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-32540(13)"
extern "C" int f_800387B4() {}
