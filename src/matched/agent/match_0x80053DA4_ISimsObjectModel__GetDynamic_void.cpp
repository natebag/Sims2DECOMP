// 0x80053DA4 ISimsObjectModel::GetDynamic(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x32c(3); rlwinm 3,3,26,31,31"
extern "C" int f_80053DA4() {}
