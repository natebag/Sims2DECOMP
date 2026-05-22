// 0x800F69B0 ObjectModuleImpl::ClearKillQueue(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x2044(3); stw 0,0x2048(3)"
extern "C" void f_800F69B0() {}
