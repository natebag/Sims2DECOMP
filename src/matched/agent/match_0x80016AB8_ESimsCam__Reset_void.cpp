// 0x80016AB8 ESimsCam::Reset(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-472(1); mfspr 0,8; stmw 30,0x1d0(1); stw 0,0x1dc(1); mr 30,3; li 0,0; stw 0,0x54c(30); addi 3,1,8; bl _s80016AB8_0; lwz 11,0x0(30); lis 9,-32707; lfs f0,0x6c(1); mr 3,30; lfs f1,-7384(9); stfs f0,0x64(11); lwz 9,0x0(30); lfs f0,0x68(1); stfs f0,0x60(9); lwz 11,0x0(30); lfs f0,0x78(1); stfs f0,0x70(11); lwz 9,0x0(30); lfs f0,0x74(1); stfs f0,0x6c(9); lfs f0,0x30(1); lwz 11,0x0(30); stfs f0,0x28(11); lwz 9,0x0(30); lfs f0,0x34(1); stfs f0,0x2c(9); bl _s80016AB8_1; addi 3,1,8; li 4,2; bl _s80016AB8_2; lwz 0,0x1dc(1); mtspr 8,0; lmw 30,0x1d0(1); addi 1,1,472"
extern "C" void _s80016AB8_0();
extern "C" void _s80016AB8_1();
extern "C" void _s80016AB8_2();
extern "C" void f_80016AB8() {}
