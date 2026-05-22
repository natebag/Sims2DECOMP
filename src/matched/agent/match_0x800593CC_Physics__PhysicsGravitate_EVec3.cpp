// 0x800593CC Physics::PhysicsGravitate(EVec3 (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f31,0x40(1); stmw 30,0x38(1); stw 0,0x4c(1); mr 31,3; mr 30,4; lis 3,-32707; addi 3,3,16000; crxor 6,6,6; bl _s800593CC_0; lfs f11,0x0(31); addi 3,1,8; lfs f12,0x0(30); lfs f10,0x4(31); fsubs f12,f12,f11; lfs f13,0x4(30); lfs f11,0x8(31); lfs f0,0x8(30); fsubs f13,f13,f10; stfs f12,0x8(1); fsubs f0,f0,f11; stfs f13,0xc(1); stfs f0,0x10(1); bl _s800593CC_1; fmr f31,f1; lfs f2,0xc(1); lfs f1,0x8(1); lis 3,-32707; lfs f3,0x10(1); addi 3,3,16020; fmr f4,f31; creqv 6,6,6; bl _s800593CC_2; lis 9,-32707; lis 11,-32707; lfs f0,0x3eb0(9); lfs f9,0x3eac(11); fcmpu 0,f31,f0; beq 0f; fdivs f9,f9,f31; 0:; lfs f12,0x8(1); addi 10,1,40; lfs f10,0x2c(31); addi 8,31,24; lfs f0,0xc(1); fmuls f12,f12,f9; lfs f11,0x10(1); fmuls f13,f12,f10; fmuls f0,f0,f9; stfs f13,0x28(1); stfs f0,0x1c(1); fmuls f11,f11,f9; fmuls f13,f11,f10; stfs f12,0x18(1); fmuls f0,f0,f10; stfs f13,0x30(1); stfs f0,0x2c(1); mr 3,31; stfs f11,0x20(1); mr 4,30; lwz 0,0x28(1); lwz 9,0x8(10); lwz 11,0x4(10); stw 0,0x18(31); stw 9,0x8(8); stw 11,0x4(8); bl _s800593CC_3; lwz 0,0x4c(1); mtspr 8,0; lmw 30,0x38(1); lfd f31,0x40(1); addi 1,1,72"
extern "C" void _s800593CC_0();
extern "C" void _s800593CC_1();
extern "C" void _s800593CC_2();
extern "C" void _s800593CC_3();
extern "C" void f_800593CC() {}
