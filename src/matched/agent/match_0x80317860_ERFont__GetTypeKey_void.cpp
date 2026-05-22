// 0x80317860 ERFont::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lwz 3,-12608(9)"
extern "C" int f_80317860() {}
