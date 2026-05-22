// 0x802E67F4 E3DWindow::GetFOVLengths(float (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; lfs f0,0x174(3); lfs f12,-4964(9); fdivs f0,f12,f0; stfs f0,0x0(5); lfs f13,0x160(3); fdivs f12,f12,f13; stfs f12,0x0(4)"
extern "C" void f_802E67F4() {}
