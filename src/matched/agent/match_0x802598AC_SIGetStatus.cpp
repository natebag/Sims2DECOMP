// 0x802598AC SIGetStatus (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s802598AC_0; lis 4,-13312; subfic 0,30,3; lwz 31,0x6438(4); rlwinm 0,0,3,0,28; srw 31,31,0; rlwinm. 0,31,0,28,28; beq 0f; lis 4,-32700; rlwinm 5,30,2,0,29; addi 0,4,-15952; add 4,0,5; lwz 0,0x0(4); rlwinm. 0,0,0,24,24; bne 0f; li 0,8; stw 0,0x0(4); 0:; bl _s802598AC_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802598AC_0();
extern "C" void _s802598AC_1();
extern "C" void f_802598AC() {}
