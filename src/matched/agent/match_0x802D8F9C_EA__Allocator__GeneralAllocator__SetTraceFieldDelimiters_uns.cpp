// 0x802D8F9C EA::Allocator::GeneralAllocator::SetTraceFieldDelimiters(unsigned (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stb 5,0x485(3); stb 4,0x484(3)"
extern "C" void f_802D8F9C() {}
