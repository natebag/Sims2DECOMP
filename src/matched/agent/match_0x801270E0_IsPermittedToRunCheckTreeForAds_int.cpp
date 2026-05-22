// 0x801270E0 IsPermittedToRunCheckTreeForAds(int, (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,-14233; ori 0,0,41796; cmpw 3,0; bne 1f; cmpwi 4,2; bne 0f; li 3,1; blr; 0:; cmpwi 4,10; li 3,1; beqlr; 1:; li 3,0"
extern "C" int f_801270E0() {}
