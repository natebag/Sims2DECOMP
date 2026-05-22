// 0x802CC474 ENDummy::SetID(int) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x40(3)"
extern "C" void f_802CC474() {}
