// 0x80306CC8 blendFloat(float, (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; lfs f0,-1332(9); fsubs f0,f0,f3; fmuls f0,f0,f1; fmadds f1,f2,f3,f0"
extern "C" float f_80306CC8() {}
