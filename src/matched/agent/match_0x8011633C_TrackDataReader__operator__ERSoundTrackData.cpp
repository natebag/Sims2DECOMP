// 0x8011633C TrackDataReader::operator=(ERSoundTrackData (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 0,0; stw 4,0x0(9); stw 0,0x4(9)"
extern "C" void f_8011633C() {}
