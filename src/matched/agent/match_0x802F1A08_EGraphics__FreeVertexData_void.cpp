// 0x802F1A08 EGraphics::FreeVertexData(void (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-26392(13); mr 30,4; lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; bl _s802F1A08_0; mr 4,30; bl _s802F1A08_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802F1A08_0();
extern "C" void _s802F1A08_1();
extern "C" void f_802F1A08() {}
