// 0x800A4A4C SAnimator2::PreloadDress(PropRef (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s800A4A4C_0; li 0,1; fadd f1,f1,f1; stw 0,-24592(13); frsp f1,f1; stfs f1,-24596(13); lfs f0,0x0(31); lfs f1,-24596(13); fmuls f1,f0,f1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800A4A4C_1; lis 9,-32706; lfs f0,-28588(9); fmuls f1,f1,f0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lis 9,-32706; lfs f0,0x0(3); lfs f13,-28584(9); addi 3,1,8; fmuls f0,f0,f13; stfs f0,0x8(1); bl _s800A4A4C_2; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s800A4A4C_0();
extern "C" void _s800A4A4C_1();
extern "C" void _s800A4A4C_2();

struct SAnimator2 {
    void PreloadDress();
};

void SAnimator2::PreloadDress() {
}
