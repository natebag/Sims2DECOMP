// 0x803CA578 __OSDBIntegrator (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(31); subf 4,26,29; add 3,3,0; bl _s803CA578_0; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s803CA578_0();
extern "C" int f_803CA578() {}
