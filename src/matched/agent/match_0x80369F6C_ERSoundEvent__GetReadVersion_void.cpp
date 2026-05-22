// 0x80369F6C ERSoundEvent::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10142(9)"
extern "C" int f_80369F6C() {}
