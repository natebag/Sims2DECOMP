// 0x800B3E74 BlendingTweakTool::GetAwarenessBlendTime(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800B3EEC" lines="add 3,31,3"
extern "C" void f_800B3EEC();
extern "C" void f_800B3E74() {}
