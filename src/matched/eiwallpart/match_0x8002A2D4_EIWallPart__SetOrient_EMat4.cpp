// 0x8002A2D4 EIWallPart::SetOrient(EMat4 (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 9,4; mr 11,3; lfs f0,0x10(9); lis 10,-32707; lfs f13,0x360(11); lfs f5,0x0(9); lfs f8,0x35c(11); fmuls f0,f13,f0; lfs f9,0x368(11); fmadds f5,f8,f5,f0; lfs f12,0x364(11); stfs f5,0x37c(11); lfs f4,0x370(11); lfs f0,0x14(9); lfs f11,0x4(9); fmuls f13,f13,f0; lfs f6,0x36c(11); fmadds f8,f8,f11,f13; lfs f3,0x378(11); stfs f8,0x380(11); lfs f2,0xd60(10); lfs f13,0x14(9); lfs f11,0x10(9); lfs f0,0x4(9); fmuls f13,f9,f13; lfs f7,0x0(9); fmuls f9,f9,f11; lfs f10,0x34(9); fmadds f0,f12,f0,f13; lfs f11,0x30(9); fmadds f12,f12,f7,f9; lfs f9,0x374(11); fadds f0,f0,f10; stfs f0,0xc(1); fadds f12,f12,f11; stfs f12,0x8(1); fmuls f0,f0,f8; fmadds f12,f12,f5,f0; stfs f12,0x384(11); lfs f13,0x10(9); lfs f0,0x0(9); lfs f12,0x30(9); fmuls f13,f4,f13; fmadds f0,f6,f0,f13; fadds f0,f0,f12; stfs f0,0x388(11); lfs f13,0x14(9); lfs f0,0x4(9); lfs f12,0x34(9); fmuls f4,f4,f13; fmadds f6,f6,f0,f4; stfs f2,0x390(11); fadds f6,f6,f12; stfs f6,0x38c(11); lfs f13,0x10(9); lfs f0,0x0(9); fmuls f13,f3,f13; lfs f12,0x30(9); fmadds f0,f9,f0,f13; fadds f0,f0,f12; stfs f0,0x394(11); lfs f13,0x14(9); lfs f0,0x4(9); lfs f12,0x34(9); fmuls f3,f3,f13; fmadds f9,f9,f0,f3; stfs f2,0x39c(11); fadds f9,f9,f12; stfs f9,0x398(11); bl _s8002A2D4_0; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s8002A2D4_0();

struct EIWallPart {
    void SetOrient_EMat4();
};

void EIWallPart::SetOrient_EMat4() {
}
