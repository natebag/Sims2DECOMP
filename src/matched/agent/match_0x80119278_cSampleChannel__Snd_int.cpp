// 0x80119278 cSampleChannel::Snd(int) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 3,0x18(9)"
extern "C" int f_80119278() {}
