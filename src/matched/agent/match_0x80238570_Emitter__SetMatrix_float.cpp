// 0x80238570 Emitter::SetMatrix(float (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x7c(3); cmplwi 10,0; beqlr; lfs f13,0x0(4); addi 9,4,4; addi 11,10,4; stfs f13,0x0(10); lfs f0,0x4(4); stfs f0,0x4(10); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfsu f0,0x4(9); stfsu f0,0x4(11); lfsu f13,0x4(9); stfsu f13,0x4(11); lfs f0,0x4(9); stfs f0,0x4(11)"
extern "C" void f_80238570() {}
