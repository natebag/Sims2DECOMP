// 0x800183F4 ESimsCam::IsInDeadZone(EVec3 (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 29,0x1c(1); stw 0,0x34(1); mr 30,3; mr 29,4; lwz 9,0x0(30); lfs f5,0x448(30); lfs f4,0x2c(9); lfs f2,0xc(9); lfs f3,0x28(9); lfs f1,0x8(9); bl _s800183F4_0; addi 9,30,1084; lfs f12,0x8(29); lfs f11,0x8(9); lis 10,-32707; lfs f9,0x43c(30); addi 11,1,8; lfs f10,0x4(9); fsubs f12,f12,f11; lfs f0,0x4(29); fmr f31,f1; lfs f13,0x0(29); mr 3,11; lfs f11,-7276(10); fsubs f0,f0,f10; fsubs f13,f13,f9; stfs f0,0xc(1); stfs f13,0x8(1); stfs f12,0x10(1); stfs f11,0x8(11); bl _s800183F4_1; fcmpu 7,f1,f31; mfcr 3; rlwinm 3,3,29,31,31; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x1c(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s800183F4_0();
extern "C" void _s800183F4_1();
extern "C" void f_800183F4() {}
