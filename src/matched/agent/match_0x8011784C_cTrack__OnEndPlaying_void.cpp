// 0x8011784C cTrack::OnEndPlaying(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lbz 0,0x1c(9); andi. 9,0,1; beq 0f; li 4,17; li 5,0; bl _s8011784C_0; 0:; lwz 9,0x0(31); lbz 3,0x1b(9); subfic 0,3,0; adde 3,0,3; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8011784C_0();
extern "C" void f_8011784C() {}
