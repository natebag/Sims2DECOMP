// 0x800655D4 SAnimator2::GetEngineFormatPos(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 30,0x38(1); stw 0,0x44(1); lfs f13,0x1c(4); lis 9,-32707; lfs f0,0x20(4); addi 8,1,40; lfs f12,0x4a50(9); mr 30,3; stfs f13,0x28(1); addi 11,1,8; stfs f0,0x2c(1); mr 3,4; stfs f12,0x30(1); mr 4,11; lwz 9,0x28(1); addi 5,1,24; lwz 10,0x8(8); lwz 0,0x4(8); stw 9,0x8(1); stw 0,0x4(11); stw 10,0x8(11); stfs f12,0x10(1); bl _s800655D4_0; lfs f12,0x18(1); mr 3,30; lfs f0,0x1c(1); lfs f13,0x20(1); stfs f12,0x0(30); stfs f0,0x4(30); stfs f13,0x8(30); lwz 0,0x44(1); mtspr 8,0; lmw 30,0x38(1); addi 1,1,64"
extern "C" void _s800655D4_0();
extern "C" void f_800655D4() {}
