// 0x80249008 __ashldi3 (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; beqlr; subfic 0,5,32; cmpwi 0,0; bgt 0f; neg 0,0; li 12,0; slw 11,4,0; b 1f; 0:; slw 9,3,5; srw 0,4,0; slw 12,4,5; or 11,9,0; 1:; mr 3,11; mr 4,12"
extern "C" int f_80249008() {}
