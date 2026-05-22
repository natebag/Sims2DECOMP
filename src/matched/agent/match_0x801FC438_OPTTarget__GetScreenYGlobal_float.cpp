// 0x801FC438 OPTTarget::GetScreenYGlobal(float) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32704; lfs f11,-20744(9); fcmpu 0,f1,f11; blt 0f; lis 9,-32704; fsubs f0,f1,f11; lfs f12,-20732(9); fadds f0,f0,f0; fmadds f0,f0,f12,f11; b 1f; 0:; lis 9,-32704; lis 11,-32704; lfs f0,-20740(9); fadds f12,f1,f1; lfs f11,-20736(11); fsubs f0,f0,f12; fmuls f0,f0,f11; 1:; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); extsb 3,3; addi 1,1,16"
extern "C" void f_801FC438() {}
