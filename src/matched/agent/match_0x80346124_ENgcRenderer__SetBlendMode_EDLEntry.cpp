// 0x80346124 ENgcRenderer::SetBlendMode(EDLEntry (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(4); li 9,1; stw 9,0x510(3); rlwinm 7,0,24,24,31; rlwinm 11,0,30,30,31; rlwinm 10,0,28,30,31; rlwinm 8,0,26,30,31; rlwinm 0,0,0,30,31; stb 11,0x565(3); stb 0,0x564(3); stb 10,0x566(3); stb 8,0x567(3); stb 7,0x568(3)"
extern "C" void f_80346124() {}
