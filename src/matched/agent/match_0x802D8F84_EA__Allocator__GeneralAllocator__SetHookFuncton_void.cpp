// 0x802D8F84 EA::Allocator::GeneralAllocator::SetHookFuncton(void (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x4c0(3); stw 4,0x4bc(3)"
extern "C" void f_802D8F84() {}
