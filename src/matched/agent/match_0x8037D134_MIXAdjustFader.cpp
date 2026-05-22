// 0x8037D134 MIXAdjustFader (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 5,0x18(3); lis 3,-32688; addi 0,3,-30144; mulli 3,5,96; add 3,0,3; lwz 0,0x1c(3); add 0,0,4; stw 0,0x1c(3); lwz 0,0x4(3); oris 0,0,16384; stw 0,0x4(3)"
extern "C" void f_8037D134() {}
