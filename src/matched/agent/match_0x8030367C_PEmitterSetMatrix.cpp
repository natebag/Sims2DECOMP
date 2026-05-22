// 0x8030367C PEmitterSetMatrix (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x0(4); addi 9,4,4; addi 11,3,4; stfs f13,0x0(3); lfs f0,0x4(4); stfs f0,0x4(3); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfs f0,0x4(9); stfs f0,0x4(11)"
extern "C" void f_8030367C() {}
