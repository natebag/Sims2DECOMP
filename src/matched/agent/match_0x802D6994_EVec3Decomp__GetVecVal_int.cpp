// 0x802D6994 EVec3Decomp::GetVecVal(int, (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 25,0x1c(1); stw 0,0x44(1); lis 9,-32702; mr 30,3; lfd f31,-6712(9); mr 29,4; mr 26,5; lis 25,17200; addi 31,30,104; li 27,0; li 28,3; 0:; lbz 5,0x1f(30); mr 4,29; lwz 3,0x0(30); extsb 5,5; bl _s802D6994_0; lfs f12,-12(31); stw 3,0x14(1); addic. 28,28,-1; lfs f13,0x0(31); stw 25,0x10(1); addi 31,31,4; lfd f0,0x10(1); fsub f0,f0,f31; frsp f0,f0; fmadds f0,f0,f12,f13; stfsx f0,27,26; addi 27,27,4; lbz 0,0x1f(30); extsb 0,0; add 29,29,0; bne 0b; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x1c(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s802D6994_0();
extern "C" void f_802D6994() {}
