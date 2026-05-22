// 0x801EFA00 INVTarget::CalcLastPageIdx(int) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,20164; srawi 3,4,31; ori 0,0,60495; mulhw 4,4,0; srawi 4,4,2; subf 3,3,4"
extern "C" int f_801EFA00() {}
