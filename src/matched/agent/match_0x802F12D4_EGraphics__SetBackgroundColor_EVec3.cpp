// 0x802F12D4 EGraphics::SetBackgroundColor(EVec3 (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x0(4); addi 11,3,128; lwz 0,0x8(4); lwz 9,0x4(4); stw 10,0x80(3); stw 0,0x8(11); stw 9,0x4(11); stw 6,0x10(3); stw 5,0x8c(3)"
extern "C" void f_802F12D4() {}
