// 0x800543B0 IShrubObject::Destruct(IShrubObject (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,2; bl _s800543B0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800543B0_0();
extern "C" void f_800543B0() {}
