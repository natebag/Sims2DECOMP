// 0x800AD49C dbAssert(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-24512(13); li 9,1; stw 3,-24520(13); li 11,0; stw 9,-32120(13); mr 3,0; stw 4,-24524(13); stw 5,-24516(13); stw 11,-24512(13); bl _s800AD49C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800AD49C_0();
extern "C" void f_800AD49C() {}
