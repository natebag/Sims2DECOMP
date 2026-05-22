// 0x800E3044 cXObjectImpl::ClearOverrideRenderPosition(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0xcc(3)"
extern "C" void f_800E3044() {}
