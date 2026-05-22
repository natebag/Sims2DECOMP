// 0x80306F64 CalcDeterminant(float, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmuls f3,f2,f3; fmsubs f1,f1,f4,f3"
extern "C" float f_80306F64() {}
