// 0x80116350 TrackDataReader::operator--(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; lwz 9,0x4(11); addi 9,9,-1; stw 9,0x4(11)"
extern "C" void f_80116350() {}
