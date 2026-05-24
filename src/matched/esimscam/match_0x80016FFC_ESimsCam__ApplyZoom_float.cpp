// 0x80016FFC ESimsCam::ApplyZoom(float) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lfs f0,0x448(31); lfs f12,0x2c(9); fsubs f0,f0,f1; stfs f0,0x448(31); lfs f1,0x28(9); fcmpu 0,f0,f1; bge 0f; fmr f13,f1; b 1f; 0:; fmr f13,f12; fcmpu 0,f0,f12; bgt 1f; fmr f13,f0; 1:; fmr f1,f13; stfs f13,0x448(31); mr 3,31; bl _s80016FFC_0; stfs f1,0x450(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80016FFC_0();

struct ESimsCam {
    void ApplyZoom();
};

void ESimsCam::ApplyZoom() {
}
