// 0x8007E650 DlgWrapper::SetDialogPos(EVec2 (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(4); lwz 9,0x0(4); stw 0,0xc0(3); stw 9,0xbc(3)"
extern "C" void f_8007E650() {}
