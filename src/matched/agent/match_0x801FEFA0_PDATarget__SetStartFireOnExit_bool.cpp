// 0x801FEFA0 PDATarget::SetStartFireOnExit(bool) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x16c(3); stw 4,0x16c(3); mr 3,0"
extern "C" void f_801FEFA0() {}
