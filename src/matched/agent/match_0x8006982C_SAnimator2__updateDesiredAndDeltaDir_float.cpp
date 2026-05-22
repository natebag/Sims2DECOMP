// 0x8006982C SAnimator2::updateDesiredAndDeltaDir(float (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; bl _s8006982C_0; mr 3,30; stfs f1,0x0(29); bl _s8006982C_1; stfs f1,0x0(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8006982C_0();
extern "C" void _s8006982C_1();
extern "C" void f_8006982C() {}
