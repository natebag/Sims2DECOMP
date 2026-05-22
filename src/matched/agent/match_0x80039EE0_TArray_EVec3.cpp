// 0x80039EE0 TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80039F00" lines="li 4,2; bl _s80039EE0_0; addi 3,1,8; li 4,2; bl _s80039EE0_1; li 3,1"
extern "C" void _s80039EE0_0();
extern "C" void _s80039EE0_1();
extern "C" void f_80039F00();
extern "C" void f_80039EE0() {}
