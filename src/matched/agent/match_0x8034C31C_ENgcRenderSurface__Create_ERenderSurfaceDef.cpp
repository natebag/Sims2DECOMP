// 0x8034C31C ENgcRenderSurface::Create(ERenderSurfaceDef (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); li 0,0; addi 9,1,8; stw 0,0x8(1); li 8,64; li 10,32; li 11,1; stb 10,0x1a(9); mr 30,4; sth 8,0x10(9); mr 4,9; stb 11,0x18(9); mr 29,3; sth 8,0x12(9); stb 0,0x19(9); stb 0,0x1b(9); stw 0,0x1c(9); stw 0,0x4(9); stw 0,0x8(9); sth 0,0x14(9); sth 0,0x16(9); lhz 9,0x6(30); lhz 11,0x2(30); lwz 0,0x10(1); sth 11,0x18(1); ori 0,0,128; sth 9,0x1a(1); stw 0,0x10(1); lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,11,3; blrl; mr 0,3; li 4,1; stw 0,0x28(29); bl _s8034C31C_0; mr 3,29; mr 4,30; bl _s8034C31C_1; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s8034C31C_0();
extern "C" void _s8034C31C_1();
extern "C" void f_8034C31C() {}
