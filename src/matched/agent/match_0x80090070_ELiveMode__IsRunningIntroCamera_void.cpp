// 0x80090070 ELiveMode::IsRunningIntroCamera(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_80090070() {}
