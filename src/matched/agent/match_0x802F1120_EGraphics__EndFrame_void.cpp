// 0x802F1120 EGraphics::EndFrame(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lwz 9,0x0(30); lwz 0,0x17c(9); lha 3,0x178(9); mtspr 8,0; add 3,30,3; blrl; lwz 3,-26512(13); li 0,0; stw 0,0x4(30); bl _s802F1120_0; lwz 29,-25912(13); lwz 3,-26512(13); lwz 30,0x338(29); lwz 28,-26816(13); lha 0,0x30(30); addi 30,30,48; add 29,29,0; bl _s802F1120_1; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,28; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802F1120_0();
extern "C" void _s802F1120_1();
extern "C" void f_802F1120() {}
