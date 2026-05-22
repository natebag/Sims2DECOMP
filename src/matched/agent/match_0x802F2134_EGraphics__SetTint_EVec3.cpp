// 0x802F2134 EGraphics::SetTint(EVec3 (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x0(4); addi 11,3,768; lwz 0,0x8(4); addi 8,3,780; lwz 9,0x4(4); stw 10,0x300(3); stw 0,0x8(11); stw 9,0x4(11); lwz 0,0x0(5); lwz 9,0x8(5); lwz 11,0x4(5); stw 0,0x30c(3); stw 9,0x8(8); stw 11,0x4(8)"
extern "C" void f_802F2134() {}
