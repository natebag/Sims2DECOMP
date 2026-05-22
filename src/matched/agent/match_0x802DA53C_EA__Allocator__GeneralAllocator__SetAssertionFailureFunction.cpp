// 0x802DA53C EA::Allocator::GeneralAllocator::SetAssertionFailureFunction(void (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 5,0x4d4(3); stw 4,0x4d0(3)"
extern "C" void f_802DA53C() {}
