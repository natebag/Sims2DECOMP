// 0x800EB7F4 cXObjectImpl::GetNext(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x5c(3); li 3,0; cmplwi 9,0; beqlr; lwz 3,0x4(9)"
extern "C" int f_800EB7F4() {}
