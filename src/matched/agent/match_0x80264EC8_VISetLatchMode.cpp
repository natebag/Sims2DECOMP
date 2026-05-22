// 0x80264EC8 __VISetLatchMode (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-13312; lhz 6,0x2002(4); addi 5,4,8192; rlwinm 4,3,4,0,27; rlwinm 0,3,6,0,25; rlwinm 3,6,0,28,25; or 3,3,4; rlwinm 3,3,0,26,23; or 0,3,0; sth 0,0x2(5)"
extern "C" void f_80264EC8() {}
