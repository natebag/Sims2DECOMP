// 0x80267008 AISetStreamTrigger (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13312; stw 3,0x6c0c(4)"
extern "C" void f_80267008() {}
