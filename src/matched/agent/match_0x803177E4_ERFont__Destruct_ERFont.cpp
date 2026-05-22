// 0x803177E4 ERFont::Destruct(ERFont (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,2; bl _s803177E4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803177E4_0();
extern "C" void f_803177E4() {}
