// 0x800A752C StringSet::CreateInstance(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,20; bl _s800A752C_0; bl _s800A752C_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A752C_0();
extern "C" void _s800A752C_1();
extern "C" void f_800A752C() {}
