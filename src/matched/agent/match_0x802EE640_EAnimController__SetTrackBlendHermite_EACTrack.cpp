// 0x802EE640 EAnimController::SetTrackBlendHermite(EACTrack (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); fmr f11,f1; mr. 4,4; beq 3f; lwz 0,0xa8(4); cmpwi 0,1; bne 3f; lfs f0,0x64(4); fcmpu 0,f11,f0; beq 3f; lfs f0,0x50(4); lis 9,-32702; lfs f13,-4408(9); fsubs f12,f0,f11; stb 0,0xa0(4); stfs f3,0x6c(4); fcmpu 0,f12,f13; stfs f4,0x70(4); stfs f0,0x60(4); stfs f11,0x64(4); stfs f13,0x5c(4); cror 3,2,1; bns 0f; fmuls f2,f2,f12; b 1f; 0:; fneg f0,f12; fmuls f2,f2,f0; 1:; lis 9,-32702; lfs f1,-4408(9); fcmpu 0,f2,f1; bne 2f; fmr f1,f11; li 5,1; bl _s802EE640_0; b 3f; 2:; fcmpu 0,f11,f1; stfs f2,0x68(4); beq 3f; li 5,1; bl _s802EE640_1; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802EE640_0();
extern "C" void _s802EE640_1();
extern "C" void f_802EE640() {}
