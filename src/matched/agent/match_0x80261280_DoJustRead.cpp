// 0x80261280 DoJustRead (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 7,-32694; stw 0,0x4(1); li 0,-1; stwu 1,-8(1); stw 0,-16952(7); li 0,0; stw 0,-23292(13); bl _s80261280_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80261280_0();
extern "C" void f_80261280() {}
