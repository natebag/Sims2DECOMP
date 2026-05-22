// 0x803921AC VMQuit (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,-21876(13); cmpwi 0,1; bne 0f; bl _s803921AC_0; li 3,1; bl _s803921AC_1; li 3,0; bl _s803921AC_2; li 3,1; bl _s803921AC_3; li 3,0; li 0,16384; stw 3,-21896(13); stw 3,-21892(13); stw 3,-21888(13); stw 0,-25224(13); stw 3,-21884(13); stw 3,-21880(13); stw 3,-21876(13); 0:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s803921AC_0();
extern "C" void _s803921AC_1();
extern "C" void _s803921AC_2();
extern "C" void _s803921AC_3();
extern "C" void f_803921AC() {}
