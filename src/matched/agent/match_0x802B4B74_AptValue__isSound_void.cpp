// 0x802B4B74 AptValue::isSound(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 9,0; rlwinm 0,3,0,25,31; cmpwi 0,21; bne 0f; rlwinm 9,3,5,31,31; 0:; mr 3,9"
extern "C" int f_802B4B74() {}
