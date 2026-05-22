// 0x802F12FC EGraphics::GetBackgroundColor(EVec3 (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 9,3,128; lwz 10,0x80(3); lwz 0,0x8(9); lwz 11,0x4(9); stw 0,0x8(4); stw 10,0x0(4); stw 11,0x4(4); lwz 0,0x8c(3); stw 0,0x0(5)"
extern "C" void f_802F12FC() {}
