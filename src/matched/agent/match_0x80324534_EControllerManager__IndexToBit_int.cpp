// 0x80324534 EControllerManager::IndexToBit(int) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; slw 3,0,3"
extern "C" int f_80324534() {}
