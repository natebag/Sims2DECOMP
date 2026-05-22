// 0x8024FE60 OSSetStringTable (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32768; stw 3,0x30d0(4)"
extern "C" void f_8024FE60() {}
