// 0x800EB2D4 cXObjectImpl::GetType(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x88(3); lha 3,0x12(9)"
extern "C" int f_800EB2D4() {}
