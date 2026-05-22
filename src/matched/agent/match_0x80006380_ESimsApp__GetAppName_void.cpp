// 0x80006380 ESimsApp::GetAppName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32707; addi 3,3,-20600"
extern "C" int f_80006380() {}
