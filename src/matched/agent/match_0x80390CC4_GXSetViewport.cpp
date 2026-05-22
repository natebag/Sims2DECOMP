// 0x80390CC4 __GXSetViewport (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 6,-17720(13); lis 3,5; lfs f1,-17344(13); li 5,16; lfs f3,0x500(6); lfs f2,0x4fc(6); lis 4,-13311; fneg f0,f3; lfs f5,0x4f4(6); fmuls f7,f2,f1; lfs f4,0x4f8(6); addi 0,3,4122; fmuls f3,f3,f1; lfs f2,0x508(6); lfs f6,0x510(6); fmuls f8,f0,f1; lfs f1,0x504(6); lfs f0,0x50c(6); fmuls f9,f2,f6; fmuls f1,f1,f6; lfs f6,-17340(13); stb 5,-32768(4); fadds f5,f5,f7; stw 0,-32768(4); fadds f2,f4,f3; stfs f7,-32768(4); fsubs f1,f9,f1; fadds f3,f6,f5; stfs f8,-32768(4); fadds f2,f6,f2; stfs f1,-32768(4); fadds f0,f9,f0; stfs f3,-32768(4); stfs f2,-32768(4); stfs f0,-32768(4)"
extern "C" void f_80390CC4() {}
