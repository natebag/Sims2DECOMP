// 0x8038CB6C TArray<ENCameraPoint, (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8038CBA8" lines="fmuls f0,f1,f4; fmuls f1,f3,f2; fdivs f3,f1,f4; fdivs f4,f1,f0"
extern "C" void f_8038CBA8();
extern "C" void f_8038CB6C() {}
