// 0x80388EAC __GXFifoInit (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32711; stw 0,0x4(1); addi 4,3,-31360; li 3,17; stwu 1,-8(1); bl _s80388EAC_0; li 3,16384; bl _s80388EAC_1; bl _s80388EAC_2; li 0,0; stw 3,-21952(13); stw 0,-21944(13); stw 0,-21960(13); stw 0,-21956(13); lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80388EAC_0();
extern "C" void _s80388EAC_1();
extern "C" void _s80388EAC_2();
extern "C" void f_80388EAC() {}
