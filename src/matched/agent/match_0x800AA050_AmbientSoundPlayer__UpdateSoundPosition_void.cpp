// 0x800AA050 AmbientSoundPlayer::UpdateSoundPosition(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lfs f11,-26800(13); lfs f12,0x14(3); lfs f10,0x18(3); lfs f0,0x20(3); lfs f13,0x24(3); fmadds f0,f0,f11,f12; lwz 9,0x4(3); fmadds f13,f13,f11,f10; stfs f0,0x14(3); stfs f13,0x18(3); lbz 0,0x19(9); andi. 9,0,1; beq 0f; bl _s800AA050_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800AA050_0();
extern "C" void f_800AA050() {}
