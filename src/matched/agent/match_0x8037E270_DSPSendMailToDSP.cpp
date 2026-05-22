// 0x8037E270 DSPSendMailToDSP (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13312; rlwinm 0,3,16,16,31; sth 0,0x5000(4); sth 3,0x5002(4)"
extern "C" void f_8037E270() {}
