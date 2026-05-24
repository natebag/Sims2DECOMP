// 0x80057C50 MorphUtilities::ApplyAllMorphs(CasSimDescriptionS2C (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lfs f1,0xf8(30); li 4,0; bl _s80057C50_0; lfs f1,0xfc(30); mr 3,29; li 4,1; bl _s80057C50_1; lfs f1,0x100(30); mr 3,29; li 4,3; bl _s80057C50_2; lfs f1,0x104(30); mr 3,29; bl _s80057C50_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80057C50_0();
extern "C" void _s80057C50_1();
extern "C" void _s80057C50_2();
extern "C" void _s80057C50_3();

struct MorphUtilities {
    void ApplyAllMorphs_CasSimDescriptionS2C();
};

void MorphUtilities::ApplyAllMorphs_CasSimDescriptionS2C() {
}
