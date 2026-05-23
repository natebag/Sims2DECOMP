// 0x800EB0BC cXObjectImpl::GetRect(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,112"
extern "C" int f_800EB0BC() {}
