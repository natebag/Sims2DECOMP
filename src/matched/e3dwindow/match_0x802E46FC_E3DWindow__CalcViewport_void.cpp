// 0x802E46FC E3DWindow::CalcViewport(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lfs f7,0x0(9); lfs f10,0x30(9); lfs f8,0x14(9); lfs f9,0x34(9); lfs f0,0x220(9); lfs f12,0x224(9); lfs f11,0x228(9); fmadds f0,f0,f7,f10; lfs f13,0x22c(9); fmadds f12,f12,f8,f9; fmadds f11,f11,f7,f10; stfs f0,0x230(9); fmadds f13,f13,f8,f9; stfs f12,0x234(9); stfs f11,0x238(9); stfs f13,0x23c(9); bl _s802E46FC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802E46FC_0();

struct E3DWindow {
    void CalcViewport();
};

void E3DWindow::CalcViewport() {
}
