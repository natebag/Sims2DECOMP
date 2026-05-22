// 0x802CAA8C EMat4::LookAtDirect(EVec3 (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f30,0x28(1); stfd f31,0x30(1); stmw 28,0x18(1); stw 0,0x3c(1); mr 29,5; mr 30,4; mr 28,3; mr 4,29; mr 3,30; fmr f30,f1; bl _s802CAA8C_0; addi 31,1,8; bl _s802CAA8C_1; lfs f10,0x0(30); fmr f31,f1; lfs f11,0x4(30); mr 3,31; lfs f8,0x8(29); lfs f12,0x0(29); lfs f13,0x8(30); fmuls f0,f10,f8; lfs f9,0x4(29); fmuls f7,f11,f12; fmsubs f12,f13,f12,f0; fmuls f13,f13,f9; stfs f12,0xc(1); fmsubs f11,f11,f8,f13; fmsubs f10,f10,f9,f7; stfs f11,0x8(1); stfs f10,0x10(1); bl _s802CAA8C_2; lis 9,-32702; lfs f13,-7444(9); fcmpu 0,f1,f13; bne 0f; lis 9,-32702; stfs f13,0x8(1); lfs f0,-7440(9); stfs f13,0x8(31); stfs f0,0x4(31); b 1f; 0:; lis 9,-32702; lfs f0,0x8(1); lfs f12,-7440(9); fdivs f12,f12,f1; fmuls f0,f0,f12; stfs f0,0x8(1); lfs f13,0x4(31); lfs f0,0x8(31); fmuls f13,f13,f12; fmuls f0,f0,f12; stfs f13,0x4(31); stfs f0,0x8(31); 1:; fmuls f1,f30,f31; mr 3,28; addi 4,1,8; bl _s802CAA8C_3; mr 3,28; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x18(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s802CAA8C_0();
extern "C" void _s802CAA8C_1();
extern "C" void _s802CAA8C_2();
extern "C" void _s802CAA8C_3();
extern "C" void f_802CAA8C() {}
