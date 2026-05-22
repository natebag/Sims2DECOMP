// 0x8016A7A4 NeighborhoodImpl::GetNeighborhoodVar(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8016A7EC" lines="addi 3,1,8; crxor 6,6,6; bl _s8016A7A4_0"
extern "C" void _s8016A7A4_0();
extern "C" void f_8016A7EC();
extern "C" void f_8016A7A4() {}
