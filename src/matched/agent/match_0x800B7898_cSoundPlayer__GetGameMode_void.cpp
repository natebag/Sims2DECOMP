// 0x800B7898 cSoundPlayer::GetGameMode(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-24508(13); cmplwi 9,0; li 3,3; beqlr; lwz 3,0x30(9)"
extern "C" int f_800B7898() {}
