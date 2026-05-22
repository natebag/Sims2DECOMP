// 0x800044B4 ESimsApp::GetBuildVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32707; addi 3,3,-19856"
extern "C" int f_800044B4() {}
