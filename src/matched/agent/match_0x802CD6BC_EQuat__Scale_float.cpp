// 0x802CD6BC EQuat::Scale(float, (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 29,0x2c(1); stw 0,0x44(1); lis 9,-32702; fmr f31,f1; lfs f0,-7276(9); mr 29,3; mr 31,4; fcmpu 0,f31,f0; bne 0f; stfs f0,0x0(29); lis 9,-32702; stfs f0,0x8(29); stfs f0,0x4(29); lfs f0,-7272(9); stfs f0,0xc(29); b 2f; 0:; lis 9,-32702; lfs f13,-7272(9); fcmpu 0,f31,f13; bne 1f; lwz 10,0xc(31); lwz 0,0x0(31); lwz 9,0x4(31); lwz 11,0x8(31); stw 0,0x0(29); stw 9,0x4(29); stw 11,0x8(29); stw 10,0xc(29); b 2f; 1:; addi 30,1,8; fmr f1,f31; stfs f0,0x8(30); mr 4,30; stfs f0,0x4(30); mr 5,31; stfs f0,0x8(1); mr 3,29; stfs f13,0xc(30); bl _s802CD6BC_0; lfs f11,0xc(31); fmr f1,f31; lfs f12,0x0(31); mr 4,30; lfs f13,0x4(31); mr 3,29; lfs f0,0x8(31); addi 5,1,24; stfs f12,0x18(1); stfs f13,0x1c(1); stfs f0,0x20(1); stfs f11,0x24(1); bl _s802CD6BC_1; 2:; mr 3,29; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x2c(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s802CD6BC_0();
extern "C" void _s802CD6BC_1();
extern "C" void f_802CD6BC() {}
