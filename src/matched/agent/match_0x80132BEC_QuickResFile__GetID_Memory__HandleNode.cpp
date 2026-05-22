// 0x80132BEC QuickResFile::GetID(Memory::HandleNode (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; sth 0,0x0(5)"
extern "C" void f_80132BEC() {}
