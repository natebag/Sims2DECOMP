// 0x8036858C ERBinary::GetReadVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32688; lhz 3,-10262(9)"
extern "C" int f_8036858C() {}
