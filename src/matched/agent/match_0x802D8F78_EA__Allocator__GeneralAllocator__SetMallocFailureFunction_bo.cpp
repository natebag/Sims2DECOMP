// 0x802D8F78 EA::Allocator::GeneralAllocator::SetMallocFailureFunction(bool (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x4c8(3); stw 4,0x4c4(3)"
extern "C" void f_802D8F78() {}
