// 0x802AB4D0 AptRenderingContext::multMatrix(AptMatrix (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); stmw 30,0x38(1); lwz 6,0x0(3); addi 9,1,8; lwz 7,0x4(3); addi 11,1,32; lwz 0,0x8(3); lwz 10,0xc(3); lwz 8,0x10(3); lwz 30,0x14(3); stw 6,0x8(1); lwz 3,0x0(4); stw 30,0x14(9); stw 7,0x4(9); stw 0,0x8(9); stw 10,0xc(9); stw 8,0x10(9); lwz 9,0x4(4); lwz 0,0x14(4); lwz 10,0x8(4); lwz 8,0xc(4); lwz 7,0x10(4); stw 3,0x20(1); stw 0,0x14(11); stw 9,0x4(11); stw 10,0x8(11); stw 8,0xc(11); stw 7,0x10(11); lfs f8,0x14(1); lfs f0,0x24(1); lfs f7,0x10(1); lfs f10,0xc(1); fmuls f12,f0,f8; lfs f13,0x20(1); fmuls f0,f0,f7; lfs f6,0x8(1); lfs f11,0x2c(1); fmadds f12,f13,f10,f12; lfs f9,0x28(1); fmadds f13,f13,f6,f0; stfs f12,0x4(5); fmuls f0,f11,f7; stfs f13,0x0(5); fmadds f0,f9,f6,f0; stfs f0,0x8(5); fmuls f11,f11,f8; lfs f13,0x34(1); fmadds f9,f9,f10,f11; lfs f0,0x30(1); fmuls f8,f13,f8; lfs f11,0x18(1); lfs f12,0x1c(1); fmadds f10,f0,f10,f8; fmuls f13,f13,f7; stfs f9,0xc(5); fmadds f0,f0,f6,f13; fadds f0,f0,f11; fadds f10,f10,f12; stfs f0,0x10(5); stfs f10,0x14(5); lmw 30,0x38(1); addi 1,1,64"

struct AptRenderingContext {
    void multMatrix_AptMatrix();
};

void AptRenderingContext::multMatrix_AptMatrix() {
}
