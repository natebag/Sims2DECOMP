// 0x803380AC ENgcPerf::ClearMetrics(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-26336(13); cmpwi 0,0; beq 0f; bl _s803380AC_0; lwz 9,-26332(13); lis 11,-32700; lwz 10,-26328(13); addi 11,11,10240; addi 9,9,1; addi 11,11,8; divw 0,9,10; li 4,21; mullw 0,0,10; subf 9,0,9; rlwinm 10,9,6,0,25; stw 9,-26332(13); lwzx 3,11,10; bl _s803380AC_1; bl _s803380AC_2; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803380AC_0();
extern "C" void _s803380AC_1();
extern "C" void _s803380AC_2();
extern "C" void f_803380AC() {}
