// 0x80322AC4 REffectsAttachment::GetTypeName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-12452(9)"
extern "C" int f_80322AC4() {}
