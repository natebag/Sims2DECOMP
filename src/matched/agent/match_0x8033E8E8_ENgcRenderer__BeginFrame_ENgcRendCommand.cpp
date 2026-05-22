// 0x8033E8E8 ENgcRenderer::BeginFrame(ENgcRendCommand (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32702; li 30,0; lfs f0,0x1d2c(9); li 0,1; stw 0,-26196(13); stfs f0,-26272(13); stfs f0,-26276(13); stw 30,-26268(13); stw 30,-26264(13); stw 30,-26256(13); stw 30,0x4648(3); lwz 9,-26392(13); lwz 0,0x10(9); stw 0,0xc(9); bl _s8033E8E8_0; stw 30,-26244(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8033E8E8_0();
extern "C" void f_8033E8E8() {}
