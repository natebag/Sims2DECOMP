// 0x80293EE0 AptCIH::GetCosAngle(AptMatrix (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 9,-32704; lfs f13,0x5ca0(9); lfs f0,0x4(31); fcmpu 0,f0,f13; bne 0f; lfs f0,0x8(31); fcmpu 0,f0,f13; bne 0f; lis 9,-32704; lfs f1,0x5ca4(9); b 1f; 0:; mr 3,31; bl _s80293EE0_0; lfs f0,0x0(31); fdivs f1,f0,f1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80293EE0_0();

struct AptCIH {
    void GetCosAngle_AptMatrix();
};

void AptCIH::GetCosAngle_AptMatrix() {
}
