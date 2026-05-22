// 0x802FAB50 EShader::IsFacer(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(3); li 3,1; andi. 9,0,12; bnelr; li 3,0"
extern "C" int f_802FAB50() {}
