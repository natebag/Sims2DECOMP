// 0x8003FAFC EGlobal::GetLiveModeMenuUIString(char (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-24988(13); mr 9,3; stw 0,0x0(9)"
extern "C" void f_8003FAFC() {}
