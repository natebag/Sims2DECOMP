// 0x8001E6B8 CameraDirector::IsForceDisableHud(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x16c(3); li 3,0; cmplwi 0,1; bnelr; lis 9,-32697; lwz 0,0x5c70(9); subfic 9,0,0; adde 3,9,0"
extern "C" int f_8001E6B8() {}
