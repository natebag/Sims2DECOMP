// 0x8015E4EC TreeTableQuickData::AddRef(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0x20(9); addi 3,3,1; stw 3,0x20(9)"
extern "C" void f_8015E4EC() {}
