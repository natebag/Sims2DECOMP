// 0x8022EF84 CalculateFacerMatrix(EVec3 (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 30,0x28(1); stw 0,0x3c(1); lfs f11,0x4(4); mr 31,5; lfs f12,0x4(3); mr 30,6; lfs f13,0x8(3); fsubs f12,f12,f11; lfs f10,0x8(4); lfs f0,0x0(3); fmuls f1,f12,f12; lfs f11,0x0(4); fsubs f13,f13,f10; stfs f13,0x10(1); fsubs f0,f0,f11; stfs f12,0xc(1); fmadds f1,f0,f0,f1; stfs f0,0x8(1); bl _s8022EF84_0; fmr f31,f1; lfs f2,0x8(1); lfs f1,0xc(1); fdivs f2,f2,f31; fdivs f1,f1,f31; bl _s8022EF84_1; mr 3,31; bl _s8022EF84_2; cmpwi 30,0; bne 2f; lfs f0,0x8(1); addi 9,1,8; lis 11,-32704; mr 30,9; stfs f0,0x18(1); lfs f12,-4204(11); lfs f13,0x4(9); fcmpu 0,f0,f12; stfs f13,0x1c(1); lfs f0,0x8(9); stfs f0,0x20(1); bne 0f; fcmpu 0,f13,f12; bne 0f; fcmpu 0,f0,f12; beq 1f; 0:; addi 3,1,24; mr 4,3; bl _s8022EF84_3; 1:; lfs f12,0x8(1); lis 9,-32704; lfs f0,0xc(1); addi 3,1,24; fdivs f12,f12,f31; lfs f13,-4204(9); mr 4,30; stfs f13,0x10(1); fdivs f0,f0,f31; stfs f12,0x8(1); stfs f0,0xc(1); bl _s8022EF84_4; mr 3,31; fneg f1,f1; bl _s8022EF84_5; 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s8022EF84_0();
extern "C" void _s8022EF84_1();
extern "C" void _s8022EF84_2();
extern "C" void _s8022EF84_3();
extern "C" void _s8022EF84_4();
extern "C" void _s8022EF84_5();
extern "C" void f_8022EF84() {}
