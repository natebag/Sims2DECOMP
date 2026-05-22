// 0x80153248 XRoute::GetCurrentGoal(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x54(3); lwz 3,0x0(3); rlwinm 0,0,4,0,27; add 3,3,0"
extern "C" int f_80153248() {}
