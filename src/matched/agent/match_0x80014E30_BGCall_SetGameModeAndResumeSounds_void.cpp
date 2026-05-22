// 0x80014E30 BGCall_SetGameModeAndResumeSounds(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-21492(13); li 4,1; bl _s80014E30_0; lwz 3,-21492(13); bl _s80014E30_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80014E30_0();
extern "C" void _s80014E30_1();
extern "C" void f_80014E30() {}
