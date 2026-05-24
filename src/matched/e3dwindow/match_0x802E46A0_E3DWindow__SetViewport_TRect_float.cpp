// 0x802E46A0 E3DWindow::SetViewport(TRect<float> (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 9,4; mr 30,3; lfs f13,0x0(9); addi 11,30,544; stfs f13,0x220(30); lfs f0,0x4(9); stfs f0,0x4(11); lfs f13,0x8(9); stfs f13,0x8(11); lfs f0,0xc(9); stfs f0,0xc(11); bl _s802E46A0_0; mr 3,30; bl _s802E46A0_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802E46A0_0();
extern "C" void _s802E46A0_1();

struct E3DWindow {
    void SetViewport_TRect();
};

void E3DWindow::SetViewport_TRect() {
}
