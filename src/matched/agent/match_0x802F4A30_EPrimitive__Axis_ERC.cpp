// 0x802F4A30 EPrimitive::Axis(ERC (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-560(1); mfspr 0,8; stfd f30,0x220(1); stfd f31,0x228(1); stmw 23,0x1fc(1); stw 0,0x234(1); li 0,6; mr 24,3; mtspr 9,0; fmr f30,f1; addi 28,1,488; addi 31,1,8; addi 3,1,88; addi 27,1,168; addi 25,1,248; addi 26,1,328; addi 23,1,408; 0:; bdnz 0b; lis 9,-32702; li 29,128; lfs f31,-3432(9); li 30,0; stw 29,0x38(1); mr 4,31; stfs f31,0x1e8(1); stw 30,0x3c(1); stw 30,0x40(1); stw 29,0x44(1); stfs f31,0x4(28); stfs f31,0x8(28); lfs f0,0x1e8(1); lfs f13,0x1ec(1); stfs f0,0x8(1); stfs f13,0x4(31); lfs f0,0x1f0(1); stfs f0,0x8(31); bl _s802F4A30_0; stfs f30,0x1e8(1); mr 4,31; stfs f31,0x4(28); mr 3,27; stfs f31,0x8(28); lfs f0,0x1e8(1); lfs f13,0x1ec(1); lfs f12,0x1f0(1); stfs f0,0x58(1); stfs f13,0x5c(1); stfs f12,0x60(1); bl _s802F4A30_1; stw 30,0xd8(1); mr 4,27; stw 29,0xdc(1); mr 3,25; stw 30,0xe0(1); stw 29,0xe4(1); bl _s802F4A30_2; stfs f31,0x1e8(1); mr 4,31; stfs f30,0x1ec(1); mr 3,26; stfs f31,0x8(28); lfs f0,0x1e8(1); lfs f13,0x1ec(1); lfs f12,0x1f0(1); stfs f0,0xf8(1); stfs f13,0xfc(1); stfs f12,0x100(1); bl _s802F4A30_3; mr 4,26; stw 30,0x17c(1); stw 29,0x184(1); mr 3,23; stw 30,0x178(1); stw 29,0x180(1); bl _s802F4A30_4; stfs f31,0x1e8(1); mr 4,31; stfs f31,0x4(28); li 5,6; stfs f30,0x1a0(1); lfs f0,0x1e8(1); lfs f13,0x1ec(1); stfs f0,0x198(1); stfs f13,0x19c(1); stfs f30,0x1f0(1); lwz 9,0x70(24); lha 3,0x70(9); lwz 0,0x74(9); add 3,24,3; mtspr 8,0; blrl; lwz 0,0x234(1); mtspr 8,0; lmw 23,0x1fc(1); lfd f30,0x220(1); lfd f31,0x228(1); addi 1,1,560"
extern "C" void _s802F4A30_0();
extern "C" void _s802F4A30_1();
extern "C" void _s802F4A30_2();
extern "C" void _s802F4A30_3();
extern "C" void _s802F4A30_4();
extern "C" void f_802F4A30() {}
