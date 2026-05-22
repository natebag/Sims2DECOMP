// 0x801E45B8 WAFTarget::OnBottomBarTweenComplete(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lfs f13,0x27c(9); lfs f0,0x274(9); fcmpu 0,f13,f0; bne 0f; li 0,1; stw 0,0x268(9); 0:; lfs f0,0x27c(9); li 0,0; stw 0,0x264(9); mr 3,9; stfs f0,0x278(9); bl _s801E45B8_0; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801E45B8_0();
extern "C" void f_801E45B8() {}
