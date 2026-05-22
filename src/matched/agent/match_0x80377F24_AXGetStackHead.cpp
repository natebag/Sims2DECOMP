// 0x80377F24 __AXGetStackHead (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32690; rlwinm 3,3,2,0,29; addi 0,4,-3232; add 3,0,3; lwz 3,0x0(3)"
extern "C" int f_80377F24() {}
