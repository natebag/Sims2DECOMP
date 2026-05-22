// 0x80116DC4 cHitMan::SetSequenceGroupTrackId(int, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,10; addi 3,3,84; rlwinm 4,4,2,0,29; stwx 5,3,4"
extern "C" void f_80116DC4() {}
