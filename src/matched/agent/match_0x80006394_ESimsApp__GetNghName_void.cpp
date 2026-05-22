// 0x80006394 ESimsApp::GetNghName(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32688; addi 3,3,-20016"
extern "C" int f_80006394() {}
