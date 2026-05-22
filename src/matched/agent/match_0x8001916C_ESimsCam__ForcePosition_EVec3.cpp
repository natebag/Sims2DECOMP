// 0x8001916C ESimsCam::ForcePosition(EVec3 (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f30,0x38(1); stfd f31,0x40(1); stmw 29,0x2c(1); stw 0,0x4c(1); lwz 11,0x0(4); mr 31,3; lwz 10,0x4(4); addi 9,31,1048; lwz 0,0x8(4); mr 30,5; stw 11,0x418(31); addi 3,1,8; stw 0,0x8(9); mr 29,6; stw 10,0x4(9); lfs f9,0x8(4); lfs f11,0x0(4); lfs f10,0x4(4); lfs f12,0x4(30); lfs f0,0x8(30); lfs f13,0x0(30); fsubs f12,f12,f10; fsubs f0,f0,f9; stfs f12,0xc(1); fsubs f13,f13,f11; stfs f0,0x10(1); stfs f13,0x8(1); bl _s8001916C_0; addi 3,1,8; fmr f30,f1; bl _s8001916C_1; lwz 9,0x0(31); fmr f31,f1; addi 3,1,24; addi 11,9,200; addi 10,9,188; lfs f9,0xbc(9); lfs f0,0xc8(9); lfs f12,0x8(11); lfs f11,0x8(10); fsubs f0,f0,f9; lfs f13,0x4(11); lfs f10,0x4(10); fsubs f12,f12,f11; stfs f0,0x18(1); fsubs f13,f13,f10; stfs f12,0x20(1); stfs f13,0x1c(1); bl _s8001916C_2; lis 9,-32707; fsubs f31,f31,f1; lfs f0,-7204(9); fcmpu 0,f31,f0; bge 0f; lis 9,-32707; lfs f0,-7200(9); fadds f31,f31,f0; 0:; lis 9,-32707; lis 11,-32707; lfs f13,-7196(9); li 0,1; lfs f12,-7192(11); addi 3,1,8; fmuls f0,f31,f13; stw 0,0x478(31); fmuls f13,f30,f13; fdivs f0,f0,f12; fdivs f13,f13,f12; stfs f0,0x44c(31); stfs f13,0x450(31); bl _s8001916C_3; stfs f1,0x448(31); addi 10,31,1084; addi 8,31,1060; mr 3,31; lwz 0,0x0(30); lwz 9,0x8(30); lwz 11,0x4(30); stw 0,0x43c(31); stw 9,0x8(10); stw 11,0x4(10); lwz 0,0x0(29); lwz 9,0x8(29); lwz 11,0x4(29); stw 0,0x424(31); stw 9,0x8(8); stw 11,0x4(8); bl _s8001916C_4; mr 3,31; addi 4,3,16; bl _s8001916C_5; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x2c(1); lfd f30,0x38(1); lfd f31,0x40(1); addi 1,1,72"
extern "C" void _s8001916C_0();
extern "C" void _s8001916C_1();
extern "C" void _s8001916C_2();
extern "C" void _s8001916C_3();
extern "C" void _s8001916C_4();
extern "C" void _s8001916C_5();
extern "C" void f_8001916C() {}
