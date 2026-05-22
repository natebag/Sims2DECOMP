// 0x802D8740 PPM_VERIFY(EA::Allocator::GeneralAllocator (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="subfic 0,4,0; adde 3,0,4"
extern "C" int f_802D8740() {}
