// 0x801164A4 cHitMan::RegisterSourceDataRequestHandler(bool (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x30(3); li 3,1"
extern "C" void f_801164A4() {}
