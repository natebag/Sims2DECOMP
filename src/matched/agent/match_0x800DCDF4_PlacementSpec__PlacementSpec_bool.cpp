// 0x800DCDF4 PlacementSpec::PlacementSpec(bool) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x0(3)"
extern "C" void f_800DCDF4() {}
