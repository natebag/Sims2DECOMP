// 0x803604E8 ERTQuantize4D::EVecToFVec(EVec4 (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32702; lfs f0,0x0(4); lfs f11,0x2e98(9); fmuls f0,f0,f11; mr 11,9; mr 10,9; fctiwz f13,f0; mr 8,9; stfd f13,0x8(1); lwz 9,0xc(1); sth 9,0x0(5); lfs f0,0x4(4); fmuls f0,f0,f11; fctiwz f12,f0; stfd f12,0x8(1); lwz 11,0xc(1); sth 11,0x2(5); lfs f0,0x8(4); fmuls f0,f0,f11; fctiwz f10,f0; stfd f10,0x8(1); lwz 10,0xc(1); sth 10,0x4(5); lfs f0,0xc(4); fmuls f0,f0,f11; fctiwz f9,f0; stfd f9,0x8(1); lwz 8,0xc(1); sth 8,0x6(5); addi 1,1,16"
extern "C" void f_803604E8() {}
