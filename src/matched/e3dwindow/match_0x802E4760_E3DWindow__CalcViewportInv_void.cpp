// 0x802E4760 E3DWindow::CalcViewportInv(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lfs f8,0x30(9); lfs f7,0x34(9); lfs f12,0x230(9); lfs f11,0x234(9); lfs f0,0x238(9); fsubs f12,f12,f8; lfs f13,0x23c(9); fsubs f11,f11,f7; lfs f10,0x0(9); fsubs f0,f0,f8; lfs f9,0x14(9); fsubs f13,f13,f7; fdivs f0,f0,f10; fdivs f13,f13,f9; stfs f0,0x228(9); fdivs f12,f12,f10; stfs f13,0x22c(9); fdivs f11,f11,f9; stfs f12,0x220(9); stfs f11,0x224(9); bl _s802E4760_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s802E4760_0();

struct E3DWindow {
    void CalcViewportInv();
};

void E3DWindow::CalcViewportInv() {
}
