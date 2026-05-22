// 0x803C416C EDebugMenuItem::GetValue(char (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stb 0,0x0(4)"
extern "C" void f_803C416C() {}
