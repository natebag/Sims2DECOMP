// 0x8003D788 GameData::GetLocalizedSimsIntroMovie(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-18460(13); lis 3,12048; ori 3,3,39797; cmplwi 0,1; beqlr; lis 3,-13962; ori 3,3,6230"
extern "C" int f_8003D788() {}
