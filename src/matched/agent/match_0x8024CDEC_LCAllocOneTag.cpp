// 0x8024CDEC LCAllocOneTag (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; beq 0f; dcbi 0,4; 0:; .long 0x100027EC"
extern "C" int f_8024CDEC() {}
