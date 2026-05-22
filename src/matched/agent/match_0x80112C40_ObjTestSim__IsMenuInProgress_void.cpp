// 0x80112C40 ObjTestSim::IsMenuInProgress(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-31792(13); li 3,0; cmplwi 0,0; beqlr; lwz 0,-21348(13); cmplwi 0,0; beqlr; lwz 0,-21344(13); cmplwi 0,0; beqlr; li 3,1"
extern "C" int f_80112C40() {}
