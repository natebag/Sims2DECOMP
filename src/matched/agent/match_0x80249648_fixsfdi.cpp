// 0x80249648 __fixsfdi (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32704; lfs f0,0x218(9); fcmpu 0,f1,f0; blt 0f; bl _s80249648_0; b 1f; 0:; fneg f1,f1; bl _s80249648_1; subfic 4,4,0; subfze 3,3; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80249648_0();
extern "C" void _s80249648_1();
extern "C" void f_80249648() {}
