// 0x802E67C0 E3DWindow::GetNearFar(float (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f12,0x188(3); lis 9,-32702; lfs f11,0x198(3); lfs f10,-4968(9); fmuls f0,f12,f12; fnmadds f13,f12,f11,f11; fsubs f0,f10,f0; fdivs f13,f13,f0; fadds f12,f12,f10; stfs f13,0x0(4); fdivs f11,f11,f12; stfs f11,0x0(5)"

struct E3DWindow {
    void GetNearFar();
};

void E3DWindow::GetNearFar() {
}
