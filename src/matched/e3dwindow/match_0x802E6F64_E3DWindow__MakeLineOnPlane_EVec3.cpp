// 0x802E6F64 E3DWindow::MakeLineOnPlane(EVec3 (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 29,0x2c(1); stw 0,0x44(1); lfs f12,0x280(3); addi 11,1,24; lfs f11,0x0(5); addi 3,3,640; lfs f13,0x8(3); lis 8,-32702; fsubs f12,f12,f11; lfs f0,0x4(3); lfs f10,0x8(5); addi 3,1,8; lfs f11,0x4(5); mr 29,11; stfs f12,0x18(1); fsubs f13,f13,f10; fsubs f0,f0,f11; stfs f13,0x20(1); stfs f0,0x1c(1); mr 30,3; lwz 10,0x18(1); mr 31,4; lwz 9,0x4(11); fmr f31,f1; lwz 0,0x8(11); stw 10,0x8(1); stw 9,0x4(3); stw 0,0x8(3); lfs f13,-4944(8); lfs f0,0x8(1); stfs f13,0x10(1); fcmpu 0,f0,f13; bne 0f; lfs f0,0x4(30); fcmpu 0,f0,f13; bne 0f; lfs f0,0x8(30); fcmpu 0,f0,f13; beq 1f; 0:; mr 4,3; bl _s802E6F64_0; 1:; lfs f0,0x8(30); lis 11,-32702; lfs f12,0x4(30); lfs f13,0x8(1); fneg f0,f0; fneg f12,f12; stfs f0,0x20(1); fneg f13,f13; stfs f12,0x1c(1); stfs f13,0x18(1); lfs f0,-4940(11); lwz 0,0x8(29); lwz 9,0x18(1); fsubs f0,f31,f0; lwz 11,0x4(29); stw 0,0x8(31); stfs f0,0x8(31); stw 9,0x0(31); stw 11,0x4(31); lwz 0,0x44(1); mtspr 8,0; lmw 29,0x2c(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s802E6F64_0();

struct E3DWindow {
    void MakeLineOnPlane();
};

void E3DWindow::MakeLineOnPlane() {
}
