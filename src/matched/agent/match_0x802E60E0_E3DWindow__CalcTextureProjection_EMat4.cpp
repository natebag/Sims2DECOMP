// 0x802E60E0 E3DWindow::CalcTextureProjection(EMat4 (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stfd f30,0x68(1); stfd f31,0x70(1); stmw 28,0x58(1); stw 0,0x7c(1); mr 30,3; mr 29,4; lwz 9,0x120(30); lwz 10,0x124(30); lis 11,-32702; addi 30,30,288; lfs f31,-5032(11); stw 9,0x0(29); stw 10,0x4(29); lis 7,-32702; lis 8,-32702; lfs f0,-5028(7); lwz 9,0x8(30); lwz 10,0xc(30); addi 28,1,72; lfs f30,-5024(8); mr 4,28; stw 9,0x8(29); stw 10,0xc(29); addi 3,1,8; lwz 9,0x10(30); lwz 10,0x14(30); stw 9,0x10(29); stw 10,0x14(29); lwz 11,0x18(30); lwz 12,0x1c(30); stw 11,0x18(29); stw 12,0x1c(29); lwz 9,0x20(30); lwz 10,0x24(30); stw 9,0x20(29); stw 10,0x24(29); lwz 11,0x28(30); lwz 12,0x2c(30); stw 11,0x28(29); stw 12,0x2c(29); lwz 9,0x30(30); lwz 10,0x34(30); stw 9,0x30(29); stw 10,0x34(29); lwz 11,0x38(30); lwz 12,0x3c(30); stfs f31,0x48(1); stw 11,0x38(29); stw 12,0x3c(29); stfs f0,0x4(28); stfs f30,0x8(28); bl _s802E60E0_0; stfs f31,0x48(1); mr 4,28; stfs f31,0x4(28); addi 3,1,8; stfs f30,0x8(28); bl _s802E60E0_1; mr 3,29; mr 4,30; addi 5,1,8; bl _s802E60E0_2; lwz 0,0x7c(1); mtspr 8,0; lmw 28,0x58(1); lfd f30,0x68(1); lfd f31,0x70(1); addi 1,1,120"
extern "C" void _s802E60E0_0();
extern "C" void _s802E60E0_1();
extern "C" void _s802E60E0_2();
extern "C" void f_802E60E0() {}
