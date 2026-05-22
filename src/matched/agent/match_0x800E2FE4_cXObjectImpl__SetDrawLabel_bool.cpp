// 0x800E2FE4 cXObjectImpl::SetDrawLabel(bool) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc4(3); cmpw 0,4; beqlr; stw 4,0xc4(3)"
extern "C" void f_800E2FE4() {}
