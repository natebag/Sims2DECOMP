// 0x800158C4 {anonymous}::TurnOnMotionBlur(FrameEffectsManager (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); mr. 3,3; beq 0f; bl _s800158C4_0; mr. 6,3; beq 0f; lis 9,-32707; lis 10,-32707; lfs f0,-7568(9); lis 8,-32707; lis 11,-32707; addi 9,1,8; stfs f0,0x0(6); li 0,0; lfs f12,-7556(11); addi 7,6,20; lfs f13,-7564(10); mr 3,6; lfs f0,-7560(8); li 4,1; stfs f13,0x8(1); stfs f0,0x4(9); stw 0,0x8(9); stfs f12,0xc(1); lwz 0,0x8(1); lwz 11,0x8(9); lwz 10,0x4(9); stw 0,0x14(6); stw 11,0x8(7); stw 10,0x4(7); bl _s800158C4_1; 0:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s800158C4_0();
extern "C" void _s800158C4_1();
extern "C" void f_800158C4() {}
