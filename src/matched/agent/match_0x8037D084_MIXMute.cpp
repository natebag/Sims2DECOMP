// 0x8037D084 MIXMute (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x18(3); lis 3,-32688; addi 0,3,-30144; mulli 3,4,96; add 3,0,3; lwz 0,0x4(3); oris 0,0,4096; ori 0,0,4; stw 0,0x4(3)"
extern "C" void f_8037D084() {}
