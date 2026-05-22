// 0x800A80B8 AmbientScorePlayer::AmbientScorePlayer(bool) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 0,0; li 9,1024; li 11,2; stw 9,0x14(30); addi 8,30,32; stw 11,0x1c(30); lis 10,-32706; stw 0,0x0(30); addi 9,30,40; stw 0,0x4(30); stw 0,0x8(30); stw 0,0xc(30); stw 0,0x10(30); stw 0,0x18(30); stw 0,0x20(30); stw 0,0x4(8); lfs f0,-28420(10); stw 0,0x4(9); stw 4,0x30(30); stfs f0,0x34(30); bl _s800A80B8_0; stw 3,0x38(30); mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A80B8_0();
extern "C" void f_800A80B8() {}
