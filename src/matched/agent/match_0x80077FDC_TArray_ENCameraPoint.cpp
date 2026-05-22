// 0x80077FDC TArray<ENCameraPoint, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fcmpu 0,f1,f0; cror 3,2,0; bsolr; stfs f1,0x470(3)"
extern "C" void f_80077FDC() {}
