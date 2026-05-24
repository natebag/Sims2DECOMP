// 0x802E6D90 E3DWindow::ProjectToZPlane(EVec3 (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f31,0x48(1); stmw 28,0x38(1); stw 0,0x54(1); mr 29,3; lfs f11,0x0(5); lfs f13,0x280(29); addi 9,29,640; lfs f12,0x8(9); addi 11,1,24; fsubs f13,f13,f11; lfs f0,0x4(9); lfs f10,0x8(5); addi 3,1,8; lfs f11,0x4(5); lis 8,-32702; stfs f13,0x18(1); fsubs f12,f12,f10; fsubs f0,f0,f11; stfs f12,0x20(1); stfs f0,0x1c(1); mr 28,11; lwz 10,0x18(1); mr 30,3; lwz 9,0x4(11); mr 31,4; lwz 0,0x8(11); fmr f31,f1; stw 10,0x8(1); stw 9,0x4(3); stw 0,0x8(3); lfs f13,-4956(8); lfs f0,0x8(1); fcmpu 0,f0,f13; bne 0f; lfs f0,0x4(30); fcmpu 0,f0,f13; bne 0f; lfs f0,0x8(30); fcmpu 0,f0,f13; beq 1f; 0:; mr 4,3; bl _s802E6D90_0; 1:; lis 9,-32702; lfs f13,0x10(1); lfs f0,-4952(9); fcmpu 0,f13,f0; bge 4f; lis 9,-32702; lfs f0,0x8(1); lfs f13,-4956(9); fcmpu 0,f0,f13; stfs f13,0x10(1); bne 2f; lfs f0,0x4(30); fcmpu 0,f0,f13; bne 2f; lfs f0,0x8(30); fcmpu 0,f0,f13; beq 3f; 2:; mr 3,30; mr 4,30; bl _s802E6D90_1; 3:; lfs f0,0x8(30); lis 11,-32702; lfs f12,0x4(30); lfs f13,0x8(1); fneg f0,f0; fneg f12,f12; stfs f0,0x20(1); fneg f13,f13; stfs f12,0x1c(1); stfs f13,0x18(1); lfs f0,-4948(11); lwz 0,0x8(28); lwz 9,0x18(1); fsubs f0,f31,f0; lwz 11,0x4(28); stw 0,0x8(31); stfs f0,0x8(31); b 5f; 4:; lfs f0,0x288(29); addi 9,29,640; lfs f10,0x8(30); fsubs f0,f31,f0; lfs f12,0x8(1); fdivs f0,f0,f13; lfs f11,0x280(29); lfs f13,0x4(30); fmuls f12,f0,f12; fmuls f10,f0,f10; stfs f12,0x28(1); fmuls f0,f0,f13; stfs f10,0x30(1); stfs f0,0x2c(1); fadds f11,f11,f12; lfs f13,0x8(9); lfs f12,0x4(9); fadds f13,f13,f10; stfs f11,0x18(1); fadds f12,f12,f0; stfs f13,0x20(1); stfs f12,0x1c(1); lwz 9,0x18(1); lwz 0,0x8(28); lwz 11,0x4(28); stw 0,0x8(31); stfs f31,0x8(31); 5:; stw 9,0x0(31); stw 11,0x4(31); lwz 0,0x54(1); mtspr 8,0; lmw 28,0x38(1); lfd f31,0x48(1); addi 1,1,80"

extern "C" void _s802E6D90_0();
extern "C" void _s802E6D90_1();

struct E3DWindow {
    void ProjectToZPlane();
};

void E3DWindow::ProjectToZPlane() {
}
