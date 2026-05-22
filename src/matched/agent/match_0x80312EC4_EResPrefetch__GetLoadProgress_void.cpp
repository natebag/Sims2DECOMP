// 0x80312EC4 EResPrefetch::GetLoadProgress(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x414(3); cmpwi 0,0; beq 0f; lfs f1,0x410(3); blr; 0:; lis 9,-32702; lfs f1,0x56c(9)"
extern "C" float f_80312EC4() {}
