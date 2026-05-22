// 0x80087840 IconItem::GetColor(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lfs f0,0x20(4); addi 8,4,32; lfs f11,0x2c(4); lis 10,-32707; stfs f0,0x8(1); addi 9,1,8; lfs f12,0x7320(10); mr 11,3; lfs f0,0x4(8); stfs f0,0x4(9); lfs f13,0x8(8); stfs f12,0xc(9); stfs f13,0x8(9); stfs f11,0x14(1); lfs f12,0x8(1); lfs f11,0xc(9); lfs f0,0x4(9); lfs f13,0x8(9); stfs f12,0x0(11); stfs f0,0x4(11); stfs f13,0x8(11); stfs f11,0xc(11); addi 1,1,24"
extern "C" void f_80087840() {}
