// 0x801CF360 O2TTarget::GetScreenYGlobal(float) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32705; lfs f11,0x3ee0(9); fcmpu 0,f1,f11; blt 0f; lis 9,-32705; fsubs f0,f1,f11; lfs f12,0x3eec(9); fadds f0,f0,f0; fmadds f0,f0,f12,f11; b 1f; 0:; lis 9,-32705; lis 11,-32705; lfs f0,0x3ee4(9); fadds f12,f1,f1; lfs f11,0x3ee8(11); fsubs f0,f0,f12; fmuls f0,f0,f11; 1:; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); extsb 3,3; addi 1,1,16"
extern "C" void f_801CF360() {}
