// 0x800A6610 StringBuffer::erase(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 0,0; stb 0,0x0(9)"
extern "C" void f_800A6610() {}
