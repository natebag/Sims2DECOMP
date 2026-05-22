// 0x80035314 ESim::GetPerson(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x3d0(3)"
extern "C" int f_80035314() {}
