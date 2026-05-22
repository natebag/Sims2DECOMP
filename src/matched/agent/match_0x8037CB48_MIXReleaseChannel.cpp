// 0x8037CB48 MIXReleaseChannel (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x18(3); lis 3,-32688; addi 0,3,-30144; mulli 3,4,96; add 3,0,3; li 0,0; stw 0,0x0(3)"
extern "C" void f_8037CB48() {}
