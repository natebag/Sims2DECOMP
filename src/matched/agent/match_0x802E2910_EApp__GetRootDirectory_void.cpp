// 0x802E2910 EApp::GetRootDirectory(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x470(3); lwz 3,0x0(9)"
extern "C" int f_802E2910() {}
