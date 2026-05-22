// 0x8037BA60 __MIXGetVolume (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,-904; bgt 0f; li 3,0; blr; 0:; cmpwi 3,60; blt 1f; lis 3,1; addi 3,3,-156; blr; 1:; lis 4,-32698; addi 4,4,-31008; rlwinm 0,3,1,0,30; add 3,4,0; lhz 3,0x710(3)"
extern "C" int f_8037BA60() {}
