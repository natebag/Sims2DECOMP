// 0x80132BF8 QuickResFile::GetIndex(Memory::HandleNode (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; sth 0,0x0(5)"
extern "C" void f_80132BF8() {}
