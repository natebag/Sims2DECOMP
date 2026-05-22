// 0x802D283C EStream::IsStreamingStructure(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3)"
extern "C" int f_802D283C() {}
