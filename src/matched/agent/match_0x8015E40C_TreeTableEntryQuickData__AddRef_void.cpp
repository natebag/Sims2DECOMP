// 0x8015E40C TreeTableEntryQuickData::AddRef(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0x18(9); addi 3,3,1; stw 3,0x18(9)"
extern "C" void f_8015E40C() {}
