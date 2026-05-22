// 0x802DC554 EA::Allocator::GeneralAllocator::GetBlockSize(void (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-4(4); clrlwi 3,3,28"
extern "C" int f_802DC554() {}
