// 0x8024B050 __OSIsDebuggerPresent (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32768; lwz 3,0x40(3)"
extern "C" int f_8024B050() {}
