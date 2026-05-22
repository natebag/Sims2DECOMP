// 0x80250874 __OSModuleInit (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32768; li 0,0; stw 0,0x30cc(4); stw 0,0x30c8(4); stw 0,0x30d0(4)"
extern "C" void f_80250874() {}
