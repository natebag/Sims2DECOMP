// 0x802685B8 DBGEXISync (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; addi 3,3,26624; 0:; lwz 0,0x34(3); rlwinm. 0,0,0,31,31; bne 0b; li 3,1"
extern "C" int f_802685B8() {}
