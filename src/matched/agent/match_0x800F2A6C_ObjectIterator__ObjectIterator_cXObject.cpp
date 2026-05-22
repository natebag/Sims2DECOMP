// 0x800F2A6C ObjectIterator::ObjectIterator(cXObject (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; stw 4,0x4(9); stw 5,0x8(9); stw 4,0x0(9)"
extern "C" void f_800F2A6C() {}
