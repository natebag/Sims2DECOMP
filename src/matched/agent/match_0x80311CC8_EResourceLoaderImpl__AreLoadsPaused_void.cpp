// 0x80311CC8 EResourceLoaderImpl::AreLoadsPaused(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3e8(3)"
extern "C" int f_80311CC8() {}
