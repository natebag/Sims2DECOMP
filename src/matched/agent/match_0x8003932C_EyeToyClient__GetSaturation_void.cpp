// 0x8003932C EyeToyClient::GetSaturation(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lis 11,-32707; lfs f0,0x5a7c(9); lfs f1,0x16dc(11); fmuls f1,f0,f1"
extern "C" float f_8003932C() {}
