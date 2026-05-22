// 0x803212CC ERTexture::GetTypeVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12484(9)"
extern "C" int f_803212CC() {}
