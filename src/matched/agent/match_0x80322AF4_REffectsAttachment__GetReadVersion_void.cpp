// 0x80322AF4 REffectsAttachment::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-12442(9)"
extern "C" int f_80322AF4() {}
