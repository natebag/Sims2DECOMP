// 0x803AC794 TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_803AC7BC" lines="li 8,0; bl _s803AC794_0; lwz 9,0x10(1); li 0,1; stw 0,0x4(29); stw 9,0x0(29)"
extern "C" void _s803AC794_0();
extern "C" void f_803AC7BC();
extern "C" void f_803AC794() {}
