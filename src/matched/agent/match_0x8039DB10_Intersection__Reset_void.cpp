// 0x8039DB10 Intersection::Reset(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32707; lfs f0,0x3bc(9); stfs f0,0x10(3)"
extern "C" void f_8039DB10() {}
