// 0x8032ED68 XOSFontClearScreen(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,-26440(13); lwz 0,-26432(13); add 0,11,0; cmplw 11,0; bgelr; lis 10,4224; ori 10,10,4224; 0:; stw 10,0x0(11); addi 11,11,4; lwz 0,-26440(13); lwz 9,-26432(13); add 0,0,9; cmplw 11,0; blt 0b"
extern "C" void f_8032ED68() {}
