// 0x802E9B04 EAnimController::GetAnimVelocity(eTrackFlags, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; bl _s802E9B04_0; fmr f31,f1; mr 3,30; mr 4,29; bl _s802E9B04_1; lis 9,-32702; lfs f0,-4596(9); fcmpu 0,f1,f0; bne 0f; fmr f1,f0; b 1f; 0:; fdivs f1,f31,f1; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802E9B04_0();
extern "C" void _s802E9B04_1();
extern "C" void f_802E9B04() {}
