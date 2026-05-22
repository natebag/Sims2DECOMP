// 0x802CB224 FAMTarget::GetLotForFamily(Family (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 11,-32702; lfs f2,0x8(26); mr 3,31; lfs f13,0x18(1); lfs f12,0x1c(1); lfs f11,0x20(1); lfs f10,0x28(1); lfs f9,0x2c(1); lfs f8,0x30(1); lfs f7,0x38(1); lfs f6,0x3c(1); lfs f5,0x40(1); lfs f4,0x8(1); lfs f3,0xc(1); lfs f0,-7400(9); lfs f1,-7396(11); stfs f13,0x0(31); stfs f12,0x4(31); stfs f11,0x8(31); stfs f10,0x10(31); stfs f9,0x14(31); stfs f8,0x18(31); stfs f7,0x20(31); stfs f6,0x24(31); stfs f5,0x28(31); stfs f0,0x2c(31); stfs f4,0x30(31); stfs f3,0x34(31); stfs f2,0x38(31); stfs f1,0x3c(31); stfs f0,0xc(31); stfs f0,0x1c(31); lwz 0,0x94(1); mtspr 8,0; lmw 26,0x78(1); addi 1,1,144"
extern "C" void f_802CB224() {}
