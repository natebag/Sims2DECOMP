// 0x800D3F78 NghResFile::SetCurrentHouse(unsigned (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 4,4,-1; stw 4,0x24(3)"
extern "C" void f_800D3F78() {}
