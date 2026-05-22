// 0x8033CA48 ENgcRenderer::SetClearColor(EVec3 (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 3,4; addi 29,30,940; stw 5,0x360(30); mr 4,29; bl _s8033CA48_0; li 9,127; lis 0,255; stb 9,0x3(29); ori 0,0,65535; stw 0,0x3b0(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8033CA48_0();
extern "C" void f_8033CA48() {}
