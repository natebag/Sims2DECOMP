// 0x802665C4 ClampU8 (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 5,3,0,24,31; rlwinm 0,4,0,24,31; cmplw 5,0; bge 0f; mr 3,4; 0:; subf 3,4,3"
extern "C" int f_802665C4() {}
