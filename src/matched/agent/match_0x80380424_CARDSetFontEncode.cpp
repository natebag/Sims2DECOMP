// 0x80380424 __CARDSetFontEncode (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,3,0,16,31; lhz 4,-22008(13); cmpwi 0,2; bge 1f; cmpwi 0,0; bge 0f; b 1f; 0:; sth 3,-22008(13); 1:; mr 3,4"
extern "C" void f_80380424() {}
