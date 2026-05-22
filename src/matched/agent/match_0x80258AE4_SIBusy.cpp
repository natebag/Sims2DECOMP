// 0x80258AE4 SIBusy (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32700; lwz 0,-15972(3); cmpwi 0,-1; beq 0f; li 3,1; blr; 0:; li 3,0"
extern "C" int f_80258AE4() {}
