// 0x80293F44 AptCIH::GetVectorLength(AptMatrix (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32704; lfs f0,0x4(3); lfs f13,0x5ca8(9); fcmpu 0,f0,f13; bne 0f; lfs f0,0x8(3); fcmpu 0,f0,f13; bne 0f; lfs f1,0x0(3); b 1f; 0:; lfs f1,0x4(3); lfs f0,0x0(3); fmuls f1,f1,f1; fmadds f1,f0,f0,f1; bl _s80293F44_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80293F44_0();
extern "C" void f_80293F44() {}
