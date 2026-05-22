// 0x8014743C TreeSimImpl::GetError(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x34(3)"
extern "C" int f_8014743C() {}
