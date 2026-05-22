// 0x800730F4 SimModel::UsingHighResolutionModel(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; lwz 0,0x6210(9); li 9,0; cmpwi 0,0; bne 0f; lwz 9,0x150(3); 0:; mr 3,9"
extern "C" int f_800730F4() {}
