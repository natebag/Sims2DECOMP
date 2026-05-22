// 0x8035D25C ENCamera::GetCameraPoint(int) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mulli 5,5,96; lwz 30,0x48(4); mr 29,3; addi 11,29,4; addi 3,29,16; lwzx 0,30,5; add 30,30,5; stw 0,0x0(29); addi 9,30,4; addi 4,30,16; lfs f0,0x4(30); stfs f0,0x4(29); lfs f13,0x4(9); stfs f13,0x4(11); lfs f0,0x8(9); stfs f0,0x8(11); bl _s8035D25C_0; lfs f13,0x50(30); mr 3,29; stfs f13,0x50(29); lfs f0,0x54(30); stfs f0,0x54(29); lfs f13,0x58(30); stfs f13,0x58(29); lfs f0,0x5c(30); stfs f0,0x5c(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8035D25C_0();
extern "C" void f_8035D25C() {}
