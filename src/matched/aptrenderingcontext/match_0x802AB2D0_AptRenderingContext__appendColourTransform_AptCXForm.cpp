// 0x802AB2D0 AptRenderingContext::appendColourTransform(AptCXForm (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lfs f11,0x0(4); lfs f0,0x0(9); lis 11,-32694; lfs f13,0x4(9); fmuls f0,f0,f11; lfs f12,0x8(9); stfs f0,0x0(9); lfs f11,0xc(9); lfs f0,0x4(4); lfs f10,0x10(9); fmuls f13,f13,f0; lfs f9,0x14(9); stfs f13,0x4(9); lfs f8,0x18(9); lfs f0,0x8(4); lfs f13,0x1c(9); fmuls f12,f12,f0; stfs f12,0x8(9); lfs f0,0xc(4); fmuls f11,f11,f0; stfs f11,0xc(9); lfs f0,0x10(4); fadds f10,f10,f0; stfs f10,0x10(9); lfs f0,0x14(4); fadds f9,f9,f0; stfs f9,0x14(9); lfs f0,0x18(4); fadds f8,f8,f0; stfs f8,0x18(9); lfs f0,0x1c(4); fadds f13,f13,f0; stfs f13,0x1c(9); lwz 0,-16164(11); mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct AptRenderingContext {
    void appendColourTransform_AptCXForm();
};

void AptRenderingContext::appendColourTransform_AptCXForm() {
}
