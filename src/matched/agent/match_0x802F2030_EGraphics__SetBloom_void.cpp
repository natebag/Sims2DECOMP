// 0x802F2030 EGraphics::SetBloom(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="lwz 0,0x2cc(3); cmpwi 0,0; bne 2f; lwz 0,0x2a8(3); cmpwi 0,0; beq 1f; lfs f13,0x2ac(3); lfs f12,0x2b0(3); lfs f11,0x2b4(3); lfs f0,0x2b8(3); 0:; stfs f13,0x2e0(3); stfs f0,0x2ec(3); stfs f12,0x2e4(3); stfs f11,0x2e8(3); blr; 1:; lfs f13,0x2bc(3); lfs f12,0x2c0(3); lfs f11,0x2c4(3); lfs f0,0x2c8(3); b 0b; 2:; lfs f13,0x2d0(3); lfs f12,0x2d4(3); lfs f11,0x2d8(3); lfs f0,0x2dc(3); b 0b"
extern "C" void f_802F2030() {}
