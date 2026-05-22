// 0x800697D8 SAnimator2::DetachMonitoredTrack(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 11,-32707; lwz 3,0x8(30); lis 9,-32707; lfs f1,0x4c30(11); lfs f3,0x4c34(9); addi 3,3,820; lwz 4,0x668(30); lfs f2,-32292(13); bl _s800697D8_0; li 0,0; stw 0,0x668(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800697D8_0();
extern "C" void f_800697D8() {}
