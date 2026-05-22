// 0x8036FEB8 IsSjisLeadByte (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,24,31; cmplwi 0,129; li 4,1; li 5,0; blt 0f; cmplwi 0,159; bgt 0f; mr 5,4; 0:; cmpwi 5,0; bne 2f; rlwinm 0,3,0,24,31; cmplwi 0,224; li 3,0; blt 1f; cmplwi 0,252; bgt 1f; li 3,1; 1:; cmpwi 3,0; bne 2f; li 4,0; 2:; mr 3,4"
extern "C" int f_8036FEB8() {}
