// 0x80300A84 EWindow::ClipTest(TRect<float> (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x60(3); addi 9,3,96; lfs f0,0x0(4); li 3,0; fcmpu 0,f0,f13; cror 3,2,1; bns 0f; lfs f13,0x8(4); lfs f0,0x8(9); fcmpu 0,f13,f0; cror 3,2,0; bns 0f; lfs f13,0x4(4); lfs f0,0x4(9); fcmpu 0,f13,f0; cror 3,2,1; bns 0f; lfs f13,0xc(4); lfs f0,0xc(9); fcmpu 0,f13,f0; cror 3,2,0; bns 0f; li 3,1; 0:; xori 3,3,1"
extern "C" float f_80300A84() {}
