// 0x802498A0 __lshrdi3 (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; beqlr; subfic 0,5,32; cmpwi 0,0; bgt 0f; neg 0,0; li 11,0; srw 12,3,0; b 1f; 0:; srw 9,4,5; slw 0,3,0; srw 11,3,5; or 12,9,0; 1:; mr 3,11; mr 4,12"
extern "C" int f_802498A0() {}
