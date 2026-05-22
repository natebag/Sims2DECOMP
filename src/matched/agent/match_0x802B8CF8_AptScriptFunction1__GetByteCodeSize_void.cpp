// 0x802B8CF8 AptScriptFunction1::GetByteCodeSize(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x34(3); lwz 3,0xc(9)"
extern "C" int f_802B8CF8() {}
