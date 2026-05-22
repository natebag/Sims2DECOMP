// 0x80055AD0 EIObjTileBoundRect::AddTilePt(CTilePt (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; bl _s80055AD0_0; cmpwi 3,0; bne 4f; addi 29,1,8; mr 4,30; mr 3,29; bl _s80055AD0_1; lfs f0,0x8(1); lfs f13,0x0(31); fmr f12,f0; fcmpu 0,f13,f0; bge 0f; fmr f12,f13; 0:; lfs f0,0x8(29); lfs f13,0x8(31); stfs f12,0x0(31); fmr f12,f0; fcmpu 0,f13,f0; bge 1f; fmr f12,f13; 1:; lfs f0,0xc(1); lfs f13,0x4(31); stfs f12,0x8(31); fmr f11,f0; fcmpu 0,f13,f0; ble 2f; fmr f11,f13; 2:; lfs f0,0x14(1); lfs f12,0xc(31); stfs f11,0x4(31); fmr f13,f0; fcmpu 0,f12,f0; ble 3f; fmr f13,f12; 3:; stfs f13,0xc(31); 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80055AD0_0();
extern "C" void _s80055AD0_1();
extern "C" void f_80055AD0() {}
