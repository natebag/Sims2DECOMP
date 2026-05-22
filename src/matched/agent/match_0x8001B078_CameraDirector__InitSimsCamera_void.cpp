// 0x8001B078 CameraDirector::InitSimsCamera(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 30,3; addi 29,1,24; addi 28,1,40; lwz 3,0x170(30); addi 4,1,8; mr 5,29; mr 6,28; bl _s8001B078_0; mr 6,28; addi 4,1,8; mr 5,29; mr 3,30; bl _s8001B078_1; lwz 0,0x18(1); addi 11,30,256; lwz 9,0x4(29); addi 7,30,268; lwz 8,0x8(29); li 6,0; stw 0,0x100(30); lwz 10,0x28(1); stw 8,0x8(11); stw 9,0x4(11); lwz 11,0x4(28); lwz 0,0x8(28); stw 10,0x10c(30); stw 0,0x8(7); stw 11,0x4(7); lwz 9,0x170(30); stw 6,0x564(9); lwz 11,0x170(30); stw 6,0x568(11); lwz 3,0x170(30); bl _s8001B078_2; lis 11,-32707; lwz 10,0x170(30); lfs f0,-6944(11); lis 9,-32707; lfs f12,-6940(9); lis 11,-32707; fmuls f1,f1,f0; lfs f11,-6936(11); stfs f1,0x174(30); lwz 9,0x0(10); lfs f0,0x64(9); stfs f0,0x17c(30); lwz 9,0x0(10); lfs f0,0x60(9); stfs f0,0x178(30); lwz 9,0x0(10); lfs f0,0x70(9); stfs f0,0x180(30); lwz 9,0x0(10); lfs f0,0x6c(9); stfs f0,0x184(30); lfs f13,0x450(10); stfs f12,0x18c(30); stfs f13,0x188(30); lwz 9,0x0(10); stfs f11,0x70(9); lwz 11,0x170(30); lwz 9,0x0(11); stfs f12,0x6c(9); lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"
extern "C" void _s8001B078_0();
extern "C" void _s8001B078_1();
extern "C" void _s8001B078_2();
extern "C" void f_8001B078() {}
