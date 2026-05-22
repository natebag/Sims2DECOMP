// 0x80255298 OSGetThreadSpecific (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 4,-32768; lwz 4,0xe4(4); cmplwi 4,0; beq 0f; cmpwi 3,0; blt 0f; cmpwi 3,2; bge 0f; rlwinm 0,3,2,0,29; add 3,4,0; lwz 3,0x310(3); blr; 0:; li 3,0"
extern "C" int f_80255298() {}
