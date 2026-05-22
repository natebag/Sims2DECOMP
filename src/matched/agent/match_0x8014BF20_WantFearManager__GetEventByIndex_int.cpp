// 0x8014BF20 WantFearManager::GetEventByIndex(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,36; lwz 3,0x8(3); add 3,3,4"
extern "C" int f_8014BF20() {}
