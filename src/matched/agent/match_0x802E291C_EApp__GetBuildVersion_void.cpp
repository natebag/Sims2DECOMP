// 0x802E291C EApp::GetBuildVersion(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32702; addi 3,3,-6232"
extern "C" int f_802E291C() {}
