// 0x80360568 ERTQuantize4D::FVecToEVec(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lhz 0,0x0(4); lis 7,17200; lis 10,-32702; stw 0,0xc(1); lis 6,-32702; lfd f13,0x2ea0(10); mr 11,9; stw 7,0x8(1); mr 10,9; lfs f12,0x2ea8(6); mr 8,9; lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x0(5); lhz 0,0x2(4); stw 0,0xc(1); stw 7,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x4(5); lhz 0,0x4(4); stw 0,0xc(1); stw 7,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x8(5); lhz 0,0x6(4); stw 0,0xc(1); stw 7,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0xc(5); addi 1,1,16"
extern "C" void f_80360568() {}
