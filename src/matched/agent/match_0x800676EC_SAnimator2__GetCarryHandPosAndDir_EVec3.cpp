// 0x800676EC SAnimator2::GetCarryHandPosAndDir(EVec3 (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 9,3,308; lwz 7,0x134(3); lwz 0,0x8(9); addi 8,3,320; lwz 10,0x4(9); mr 11,5; stw 0,0x8(4); mr 5,6; stw 7,0x0(4); stw 10,0x4(4); lwz 9,0x140(3); lwz 0,0x8(8); lwz 10,0x4(8); stw 0,0x8(11); stw 9,0x0(11); stw 10,0x4(11); lwz 9,0x8(3); lwz 4,0x60c(3); addi 3,9,820; bl _s800676EC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800676EC_0();
extern "C" void f_800676EC() {}
