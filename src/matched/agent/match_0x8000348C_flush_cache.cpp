// 0x8000348C __flush_cache (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-1; ori 5,5,65521; and 5,5,3; subf 3,5,3; add 4,4,3; 0:; dcbst 0,5; sync; icbi 0,5; addic 5,5,8; addic. 4,4,-8; bge 0b; isync"
extern "C" int f_8000348C() {}
