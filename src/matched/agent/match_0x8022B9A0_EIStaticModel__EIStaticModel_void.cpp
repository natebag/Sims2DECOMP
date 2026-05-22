// 0x8022B9A0 EIStaticModel::EIStaticModel(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; addi 29,30,256; bl _s8022B9A0_0; lis 9,-32697; mr 3,29; addi 9,9,-26776; stw 9,0x0(30); bl _s8022B9A0_1; lis 9,-32704; li 0,0; lfs f0,-4616(9); addi 3,30,128; stw 0,0x110(30); stfs f0,0x8(1); stfs f0,0x10(1); stfs f0,0xc(1); lwz 9,0x8(1); lwz 11,0xc(1); lwz 10,0x10(1); stw 9,0x100(30); stfs f0,0xc(29); stw 11,0x4(29); stw 10,0x8(29); stw 0,0x124(30); stw 0,0x120(30); stw 0,0x118(30); stw 0,0x11c(30); stw 0,0x114(30); bl _s8022B9A0_2; addi 3,30,192; bl _s8022B9A0_3; lwz 0,0x5c(30); mr 3,30; ori 0,0,512; stw 0,0x5c(30); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8022B9A0_0();
extern "C" void _s8022B9A0_1();
extern "C" void _s8022B9A0_2();
extern "C" void _s8022B9A0_3();
extern "C" void f_8022B9A0() {}
