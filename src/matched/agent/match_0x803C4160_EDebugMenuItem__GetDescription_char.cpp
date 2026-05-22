// 0x803C4160 EDebugMenuItem::GetDescription(char (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stb 0,0x0(4)"
extern "C" void f_803C4160() {}
