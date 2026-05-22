// 0x803212E4 ERTexture::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12482(9)"
extern "C" int f_803212E4() {}
