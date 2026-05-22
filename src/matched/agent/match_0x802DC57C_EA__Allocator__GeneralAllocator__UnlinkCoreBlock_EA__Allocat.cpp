// 0x802DC57C EA::Allocator::GeneralAllocator::UnlinkCoreBlock(EA::Allocator::GeneralAllocator::CoreBlock (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x20(4); lwz 0,0x24(4); stw 0,0x24(9); lwz 11,0x20(4); lwz 9,0x24(4); stw 11,0x20(9)"
extern "C" void f_802DC57C() {}
