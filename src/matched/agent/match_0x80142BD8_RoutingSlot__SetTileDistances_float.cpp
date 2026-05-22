// 0x80142BD8 RoutingSlot::SetTileDistances(float, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32706; lfs f0,-10520(9); mr 10,11; mr 9,11; fmuls f1,f1,f0; fctiwz f13,f1; stfd f13,0x8(1); fmuls f2,f2,f0; lwz 11,0xc(1); fctiwz f12,f2; stfd f12,0x8(1); fmuls f3,f3,f0; stw 11,0x24(3); lwz 10,0xc(1); fctiwz f11,f3; stfd f11,0x8(1); stw 10,0x28(3); lwz 9,0xc(1); stw 9,0x2c(3); addi 1,1,16"
extern "C" void f_80142BD8() {}
