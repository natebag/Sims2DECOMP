// 0x80257D50 EXIGetState (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 3,0,4; lwz 3,0xc(3)"
extern "C" int f_80257D50() {}
