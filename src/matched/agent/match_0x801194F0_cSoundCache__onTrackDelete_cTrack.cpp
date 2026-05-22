// 0x801194F0 cSoundCache::onTrackDelete(cTrack (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 11,0; lwzx 0,3,11; cmpw 0,4; bne 0f; stwx 11,3,11; blr; 0:; addi 11,11,1; cmpwi 11,63; bgtlr; rlwinm 9,11,2,0,29; lwzx 0,3,9; cmpw 0,4; bne 0b; li 0,0; stwx 0,3,9"
extern "C" void f_801194F0() {}
