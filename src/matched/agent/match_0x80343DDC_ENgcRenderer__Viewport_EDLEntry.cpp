// 0x80343DDC ENgcRenderer::Viewport(EDLEntry (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-26060(13); cmpwi 0,0; beq 0f; li 0,0; stw 0,-26060(13); 0:; lwz 9,0x4(4); lis 10,-32702; lwz 11,0x4d8(3); lis 8,-32702; lfs f12,0x0(9); lfs f11,0x10(9); fneg f13,f12; lfs f9,0x14(9); lfs f0,0x4(9); fadds f13,f13,f11; stfs f13,0x9b0(11); fadds f12,f12,f11; fadds f10,f0,f9; lfs f11,0x1dc8(10); lwz 9,0x4d8(3); fsubs f12,f12,f13; fneg f0,f0; lfs f13,0x1dcc(8); stfs f10,0x9b4(9); fadds f0,f0,f9; fsubs f0,f0,f10; lwz 9,0x4d8(3); stfs f12,0x9b8(9); lwz 11,0x4d8(3); stfs f0,0x9bc(11); lwz 9,0x4d8(3); stfs f11,0x9c0(9); lwz 11,0x4d8(3); stfs f13,0x9c4(11); lwz 9,0x4d8(3); lwz 0,0x6cc(9); oris 0,0,32768; ori 0,0,512; stw 0,0x6cc(9)"
extern "C" void f_80343DDC() {}
