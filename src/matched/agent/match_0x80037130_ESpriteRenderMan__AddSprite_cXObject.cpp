// 0x80037130 ESpriteRenderMan::AddSprite(cXObject (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 28,3; bl _s80037130_0; li 5,16; li 6,0; li 7,0; li 4,236; bl _s80037130_1; bl _s80037130_2; mr 29,3; stw 30,0x8(29); mr 3,28; mr 4,29; bl _s80037130_3; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80037130_0();
extern "C" void _s80037130_1();
extern "C" void _s80037130_2();
extern "C" void _s80037130_3();
extern "C" void f_80037130() {}
