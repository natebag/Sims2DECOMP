// 0x80229270 EInstance::GetInstAlpha(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-28496(13); addi 3,3,96; rlwinm 0,0,2,0,29; lfsx f1,3,0"
extern "C" int f_80229270() {}
