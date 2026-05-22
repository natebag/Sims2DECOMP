// 0x8035E1D8 ERotDecomp::GetQuatVal(int, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f31,0x28(1); stmw 26,0x10(1); stw 0,0x34(1); lis 9,-32702; mr 28,5; lfd f31,0x2dc8(9); addi 27,28,12; mr 30,3; mr 29,4; lis 26,17200; addi 31,28,4; 0:; lbz 5,0x1f(30); mr 4,29; lwz 3,0x0(30); extsb 5,5; bl _s8035E1D8_0; xoris 3,3,32768; stw 3,0xc(1); lfs f13,0x24(30); stw 26,0x8(1); lfd f0,0x8(1); fsub f0,f0,f31; frsp f0,f0; fmuls f13,f13,f0; stfs f13,0x0(31); addi 31,31,4; lbz 0,0x1f(30); cmpw 31,27; extsb 0,0; add 29,29,0; ble 0b; lfs f13,0x8(28); lis 11,-32702; lfs f12,0x4(28); lis 9,-32702; fmuls f13,f13,f13; lfs f0,0xc(28); fmadds f12,f12,f12,f13; lfs f11,0x2dd0(11); lfs f13,0x2dd4(9); fmadds f0,f0,f0,f12; fsubs f1,f11,f0; fcmpu 0,f1,f13; cror 3,2,0; bns 1f; stfs f13,0x0(28); b 2f; 1:; bl _s8035E1D8_1; stfs f1,0x0(28); mr 4,29; lwz 3,0x0(30); bl _s8035E1D8_2; cmpwi 3,0; beq 2f; lfs f0,0x0(28); fneg f0,f0; stfs f0,0x0(28); 2:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x10(1); lfd f31,0x28(1); addi 1,1,48"
extern "C" void _s8035E1D8_0();
extern "C" void _s8035E1D8_1();
extern "C" void _s8035E1D8_2();
extern "C" void f_8035E1D8() {}
