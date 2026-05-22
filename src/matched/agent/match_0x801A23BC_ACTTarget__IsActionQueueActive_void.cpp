// 0x801A23BC ACTTarget::IsActionQueueActive(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xd0(3)"
extern "C" int f_801A23BC() {}
