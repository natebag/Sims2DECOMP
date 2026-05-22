// 0x8037E224 DSPCheckMailToDSP (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lhz 0,0x5000(3); rlwinm 3,0,17,31,31"
extern "C" int f_8037E224() {}
