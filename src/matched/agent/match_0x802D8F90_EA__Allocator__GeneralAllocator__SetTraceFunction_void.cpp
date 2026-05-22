// 0x802D8F90 EA::Allocator::GeneralAllocator::SetTraceFunction(void (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x4dc(3); stw 4,0x4d8(3)"
extern "C" void f_802D8F90() {}
