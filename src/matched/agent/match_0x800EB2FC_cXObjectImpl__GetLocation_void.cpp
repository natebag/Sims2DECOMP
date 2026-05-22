// 0x800EB2FC cXObjectImpl::GetLocation(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,104"
extern "C" int f_800EB2FC() {}
