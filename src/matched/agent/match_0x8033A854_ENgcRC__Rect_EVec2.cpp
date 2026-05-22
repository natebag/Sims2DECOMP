// 0x8033A854 ENgcRC::Rect(EVec2 (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stw 0,0x54(1); mr 9,4; lfs f6,0x4(5); lfs f7,0x4(9); li 0,33; lfs f5,0x4(6); lis 3,-32691; lfs f4,0x4(7); addi 3,3,21688; lfs f3,0xc(8); addi 4,1,8; lfs f0,0x0(9); lfs f9,0x4(8); lfs f8,0x8(8); lfs f13,0x0(5); lfs f12,0x0(6); lfs f11,0x0(7); lfs f10,0x0(8); stb 0,0x8(1); stfs f0,0x10(1); stfs f7,0x14(1); stfs f13,0x18(1); stfs f6,0x1c(1); stfs f12,0x20(1); stfs f5,0x24(1); stfs f11,0x28(1); stfs f4,0x2c(1); stfs f10,0x30(1); stfs f9,0x34(1); stfs f8,0x38(1); stfs f3,0x3c(1); stfs f1,0x40(1); bl _s8033A854_0; lwz 0,0x54(1); mtspr 8,0; addi 1,1,80"
extern "C" void _s8033A854_0();
extern "C" void f_8033A854() {}
