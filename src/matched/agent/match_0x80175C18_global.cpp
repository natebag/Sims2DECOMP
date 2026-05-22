// 0x80175C18 global (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80175C7C" lines="crxor 6,6,6; bl _s80175C18_0; addi 30,31,40; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s80175C18_1"
extern "C" void _s80175C18_0();
extern "C" void _s80175C18_1();
extern "C" void f_80175C7C();
extern "C" void f_80175C18() {}
