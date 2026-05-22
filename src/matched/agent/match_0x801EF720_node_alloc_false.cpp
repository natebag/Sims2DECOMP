// 0x801EF720 __node_alloc<false, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 28,31,2443; bl _s801EF720_0; lbz 9,0x138(31); addi 10,13,-28700; lwz 0,0x84(31); li 11,0; addi 9,9,-1; stb 9,0x138(31); rlwinm 0,0,2,0,29; stwx 11,10,0; mr 3,31; mr 4,28; li 5,2048; bl _s801EF720_1; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s801EF720_0();
extern "C" void _s801EF720_1();
extern "C" void f_801EF720() {}
