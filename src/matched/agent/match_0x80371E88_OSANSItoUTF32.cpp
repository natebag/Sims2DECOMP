// 0x80371E88 OSANSItoUTF32 (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,24,31; cmplwi 0,128; blt 0f; cmplwi 0,159; bgt 0f; lis 3,-32700; addi 3,3,14752; rlwinm 0,0,1,0,30; add 3,3,0; lhz 3,-256(3); blr; 0:; rlwinm 3,3,0,24,31"
extern "C" int f_80371E88() {}
