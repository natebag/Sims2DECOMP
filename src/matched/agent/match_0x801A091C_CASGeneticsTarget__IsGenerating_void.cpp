// 0x801A091C CASGeneticsTarget::IsGenerating(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-31440(13); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_801A091C() {}
