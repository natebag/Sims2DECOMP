// 0x80306958 DumpBinary64(void (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,29,3,31; cmpwi 4,0; addi 4,4,-1; beqlr; 0:; cmpwi 4,0; addi 4,4,-1; bne 0b"
extern "C" int f_80306958() {}
