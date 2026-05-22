// 0x8020AF88 InteractorModule::InteractorInputManager::GetSessionData(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); cmpwi 0,0; beq 0f; rlwinm 3,4,5,0,26; add 3,0,3; blr; 0:; li 3,0"
extern "C" int f_8020AF88() {}
