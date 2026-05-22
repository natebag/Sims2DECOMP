// 0x800694E0 SAnimator2::SetIdleAnimPlaybackParameters(EACTrack (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 9,3; mr. 31,4; beq 0f; lwz 3,0x8(9); mr 4,31; lfs f1,0xfc(9); addi 3,3,820; bl _s800694E0_0; li 0,0; stb 0,0xd(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800694E0_0();
extern "C" void f_800694E0() {}
