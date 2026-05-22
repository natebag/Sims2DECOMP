// 0x80328CE4 EyeToyManager::OpenInstance(int, (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26604(13); cmplwi 0,0; li 3,-1; bnelr; li 3,-1"
extern "C" int f_80328CE4() {}
