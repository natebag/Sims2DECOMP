// 0x80039434 EyeToyClient::GetBrightness(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lis 11,-32707; lfs f0,0x5a80(9); lfs f1,0x16fc(11); fmuls f1,f0,f1"
extern "C" float f_80039434() {}
