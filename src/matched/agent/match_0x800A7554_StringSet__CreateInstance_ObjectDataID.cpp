// 0x800A7554 StringSet::CreateInstance(ObjectDataID (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,20; bl _s800A7554_0; bl _s800A7554_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A7554_0();
extern "C" void _s800A7554_1();
extern "C" void f_800A7554() {}
