// 0x80116DD8 cHitMan::SequenceGroupTrackId(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,10; addi 3,3,84; rlwinm 4,4,2,0,29; lwzx 3,3,4"
extern "C" int f_80116DD8() {}
