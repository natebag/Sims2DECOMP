// 0x8014796C AudioTweakMenu::ResizedWindow(CUIWindow (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,0x1c(1); lwz 11,0x0(3); mr 29,4; mr 28,5; lwz 9,0x18(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; bl _s8014796C_0; sth 3,0x0(29); lhz 0,0x2(30); sth 0,0x0(28); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8014796C_0();
extern "C" void f_8014796C() {}
