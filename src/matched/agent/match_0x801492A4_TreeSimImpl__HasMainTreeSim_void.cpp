// 0x801492A4 TreeSimImpl::HasMainTreeSim(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x38(3); subfic 0,3,0; adde 3,0,3"
extern "C" int f_801492A4() {}
