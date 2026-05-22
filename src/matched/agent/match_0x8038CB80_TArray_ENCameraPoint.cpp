// 0x8038CB80 TArray<ENCameraPoint, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8038CBA8" lines="fmuls f0,f2,f1; lfs f5,-17608(13); lfs f3,-17632(13); fsubs f2,f5,f2; fmuls f0,f1,f0; fdivs f4,f2,f0"
extern "C" void f_8038CBA8();
extern "C" void f_8038CB80() {}
