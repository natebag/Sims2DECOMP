// 0x800D3860 getCurrentbuildVerNum(int, (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 3,3,24,0,7; rlwinm 4,4,16,8,15; or 3,3,4; rlwinm 5,5,8,16,23; or 3,3,5; rlwinm 6,6,0,24,31; or 3,3,6"
extern "C" int f_800D3860() {}
