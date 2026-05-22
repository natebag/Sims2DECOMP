// 0x800D5470 NghResFile::GetThumbGUID(unsigned (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,-1; addi 3,3,404; rlwinm 4,4,2,0,29; lwzx 3,3,4"
extern "C" int f_800D5470() {}
