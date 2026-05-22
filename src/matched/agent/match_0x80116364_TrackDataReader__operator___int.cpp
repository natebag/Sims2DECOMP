// 0x80116364 TrackDataReader::operator+=(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 0,0x4(9); add 0,0,4; stw 0,0x4(9)"
extern "C" void f_80116364() {}
