// 0x800E324C cXObjectImpl::GetNumTiles(int (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 0,0x0(4); stw 0,0x0(5)"
extern "C" void f_800E324C() {}
