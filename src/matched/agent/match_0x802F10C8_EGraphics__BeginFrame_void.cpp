// 0x802F10C8 EGraphics::BeginFrame(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-25912(13); mr 30,3; lwz 4,-26816(13); lwz 9,0x338(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; li 9,1; stw 0,-26708(13); stw 9,0x4(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802F10C8() {}
