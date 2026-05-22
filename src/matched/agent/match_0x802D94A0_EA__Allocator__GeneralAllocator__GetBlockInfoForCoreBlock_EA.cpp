// 0x802D94A0 EA::Allocator::GeneralAllocator::GetBlockInfoForCoreBlock(EA::Allocator::GeneralAllocator::CoreBlock (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,8; li 11,0; stb 0,0x10(5); lwz 0,0x0(4); stw 0,0x0(5); lwz 9,0x4(4); stw 11,0x14(5); stw 9,0x4(5)"
extern "C" void f_802D94A0() {}
