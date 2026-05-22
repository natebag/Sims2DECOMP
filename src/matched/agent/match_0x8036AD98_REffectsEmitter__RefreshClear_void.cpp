// 0x8036AD98 REffectsEmitter::RefreshClear(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x20(3)"
extern "C" void f_8036AD98() {}
