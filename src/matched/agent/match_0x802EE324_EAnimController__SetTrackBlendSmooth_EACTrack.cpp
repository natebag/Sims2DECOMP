// 0x802EE324 EAnimController::SetTrackBlendSmooth(EACTrack (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 4,4; beq 0f; lwz 0,0xa8(4); cmpwi 0,1; bne 0f; lfs f0,0x64(4); fcmpu 0,f1,f0; beq 0f; lis 9,-32702; li 0,2; lfs f0,-4412(9); stb 0,0xa0(4); fcmpu 0,f1,f0; stfs f3,0x58(4); stfs f2,0x68(4); stfs f1,0x64(4); stfs f2,0x54(4); beq 0f; li 5,1; bl _s802EE324_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802EE324_0();
extern "C" void f_802EE324() {}
