// 0x802F2170 EGraphics::GetTint(EVec3 (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 9,3,768; lwz 10,0x300(3); lwz 0,0x8(9); addi 8,3,780; lwz 11,0x4(9); stw 0,0x8(4); stw 10,0x0(4); stw 11,0x4(4); lwz 10,0x30c(3); lwz 0,0x8(8); lwz 9,0x4(8); stw 0,0x8(5); stw 10,0x0(5); stw 9,0x4(5)"
extern "C" void f_802F2170() {}
