// 0x802B8CE0 AptScriptFunction1::GetNumArguments(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x34(3); lwz 3,0x4(9)"
extern "C" int f_802B8CE0() {}
