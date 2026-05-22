// 0x80390E18 GXSetZScaleOffset (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-17336(13); li 6,16; lwz 7,-17720(13); lis 5,-13311; fmuls f3,f0,f2; fmuls f0,f0,f1; li 4,4124; li 3,4127; stfs f3,0x50c(7); li 0,1; lfs f1,-17348(13); fadds f2,f1,f0; stfs f2,0x510(7); lfs f1,0x508(7); lfs f0,0x504(7); fmuls f1,f1,f2; fmuls f0,f0,f2; stb 6,-32768(5); stw 4,-32768(5); fadds f3,f3,f1; fsubs f0,f1,f0; stfs f0,-32768(5); stb 6,-32768(5); stw 3,-32768(5); stfs f3,-32768(5); sth 0,0x2(7)"
extern "C" void f_80390E18() {}
