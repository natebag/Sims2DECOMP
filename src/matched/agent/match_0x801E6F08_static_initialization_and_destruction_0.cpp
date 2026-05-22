// 0x801E6F08 __static_initialization_and_destruction_0 (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmplwi 3,0; beqlr; li 0,17; stw 0,-23852(13)"
extern "C" void f_801E6F08() {}
