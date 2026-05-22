// 0x8038DE00 GXLoadTlut (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; addi 3,4,0; lwz 5,-17720(13); lwz 12,0x4cc(5); mtspr 8,12; blrl; mr 31,3; bl _s8038DE00_0; li 4,97; lis 3,-13311; stb 4,-32768(3); lwz 0,0x4(30); stw 0,-32768(3); stb 4,-32768(3); lwz 0,0x0(31); stw 0,-32768(3); bl _s8038DE00_1; lwz 3,0x0(31); lwz 0,0x0(30); rlwimi 0,3,0,22,31; stw 0,0x0(30); lwz 3,0x0(30); lwz 0,0x4(30); stw 3,0x4(31); stw 0,0x8(31); lwz 0,0x8(30); stw 0,0xc(31); lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038DE00_0();
extern "C" void _s8038DE00_1();
extern "C" void f_8038DE00() {}
