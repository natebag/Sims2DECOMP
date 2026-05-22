// 0x802377AC ERLevel::OutsideLightsUpdate(float, (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stfd f30,0x38(1); stfd f31,0x40(1); stmw 28,0x28(1); stw 0,0x4c(1); mr 28,3; mr 31,4; addis 30,28,3; fmr f31,f1; lwz 3,-7084(30); lis 29,-32695; bl _s802377AC_0; lwz 3,-7080(30); fmr f1,f31; mr 4,31; bl _s802377AC_1; addi 3,29,-29844; mr 4,31; bl _s802377AC_2; addi 29,29,-29844; lfs f30,-7076(30); lwz 0,0x44(29); cmpwi 0,0; beq 0f; lfs f30,0x70(29); b 1f; 0:; stfs f30,0x70(29); 1:; lis 9,-32704; lfs f1,0x24(31); lfs f31,-2656(9); addi 3,1,24; addi 4,1,28; fmuls f1,f1,f31; bl _s802377AC_3; lfs f1,0x28(31); addi 3,1,32; addi 4,1,36; fadds f1,f30,f1; fmuls f1,f1,f31; bl _s802377AC_4; lfs f13,0x1c(1); addi 4,1,8; lfs f0,0x24(1); addis 9,28,3; lfs f12,0x20(1); addi 6,9,-7268; lfs f11,0x18(1); fmuls f0,f13,f0; stfs f0,0x8(1); fmuls f13,f13,f12; stfs f13,0x4(4); addi 8,31,68; stfs f11,0x8(4); addi 7,9,-7296; lwz 10,0x4(4); addi 30,31,44; lwz 0,0x8(1); addi 29,9,-7112; lwz 11,0x8(4); addi 3,31,4; stw 0,-7268(9); addi 5,9,-25480; stw 11,0x8(6); stw 10,0x4(6); lwz 0,0x44(31); lwz 11,0x8(8); lwz 10,0x4(8); stw 0,-7296(9); stw 11,0x8(7); stw 10,0x4(7); lfs f0,0x50(31); stfs f0,-7300(9); lwz 0,0x2c(31); lwz 11,0x8(30); lwz 10,0x4(30); stw 0,-7112(9); stw 11,0x8(29); stw 10,0x4(29); lfs f0,0x38(31); stfs f0,-7116(9); lfs f13,0x3c(31); stfs f13,0x14(28); bl _s802377AC_5; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x28(1); lfd f30,0x38(1); lfd f31,0x40(1); addi 1,1,72"
extern "C" void _s802377AC_0();
extern "C" void _s802377AC_1();
extern "C" void _s802377AC_2();
extern "C" void _s802377AC_3();
extern "C" void _s802377AC_4();
extern "C" void _s802377AC_5();
extern "C" void f_802377AC() {}
