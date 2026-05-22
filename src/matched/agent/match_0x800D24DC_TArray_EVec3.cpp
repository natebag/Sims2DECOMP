// 0x800D24DC TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800D2494" lines="crxor 6,6,6; bl _s800D24DC_0; addi 30,30,1; addi 3,31,16; addi 4,1,8; bl _s800D24DC_1"
extern "C" void _s800D24DC_0();
extern "C" void _s800D24DC_1();
extern "C" void f_800D2494();
extern "C" void f_800D24DC() {}
