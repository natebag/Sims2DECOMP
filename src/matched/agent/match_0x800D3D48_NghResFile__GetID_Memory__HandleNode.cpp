// 0x800D3D48 NghResFile::GetID(Memory::HandleNode (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x180(3); lhz 0,0x8(9); sth 0,0x0(5)"
extern "C" void f_800D3D48() {}
