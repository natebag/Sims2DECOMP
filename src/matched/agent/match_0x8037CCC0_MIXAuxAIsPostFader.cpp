// 0x8037CCC0 MIXAuxAIsPostFader (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,0x18(3); lis 3,-32688; addi 0,3,-30144; mulli 3,4,96; add 3,0,3; lwz 0,0x4(3); rlwinm. 0,0,0,31,31; beq 0f; li 3,0; blr; 0:; li 3,1"
extern "C" int f_8037CCC0() {}
