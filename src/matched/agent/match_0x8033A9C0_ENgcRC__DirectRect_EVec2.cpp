// 0x8033A9C0 ENgcRC::DirectRect(EVec2 (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stw 0,0x44(1); lfs f9,0x4(4); li 0,41; lfs f0,0x0(4); lis 3,-32691; lfs f8,0x4(5); addi 3,3,21688; lfs f7,0xc(6); addi 4,1,8; lfs f11,0x4(6); lfs f10,0x8(6); lfs f13,0x0(5); lfs f12,0x0(6); stb 0,0x8(1); stfs f0,0x10(1); stfs f9,0x14(1); stfs f13,0x18(1); stfs f8,0x1c(1); stfs f12,0x20(1); stfs f11,0x24(1); stfs f10,0x28(1); stfs f7,0x2c(1); stfs f1,0x30(1); bl _s8033A9C0_0; lwz 0,0x44(1); mtspr 8,0; addi 1,1,64"
extern "C" void _s8033A9C0_0();
extern "C" void f_8033A9C0() {}
