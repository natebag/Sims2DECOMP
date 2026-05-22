// 0x8003D7A8 GameData::GetLocalizedSimsEndingMovie(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-18460(13); lis 3,-6765; ori 3,3,50741; cmplwi 0,1; beqlr; lis 3,-26936; ori 3,3,21331"
extern "C" int f_8003D7A8() {}
