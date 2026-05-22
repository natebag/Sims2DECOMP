// 0x802C9780 EMat4::Scale(EVec3 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s802C9780_0; lfs f13,0x0(29); mr 3,30; stfs f13,0x0(30); lfs f0,0x4(29); stfs f0,0x14(30); lfs f13,0x8(29); stfs f13,0x28(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C9780_0();
extern "C" void f_802C9780() {}
