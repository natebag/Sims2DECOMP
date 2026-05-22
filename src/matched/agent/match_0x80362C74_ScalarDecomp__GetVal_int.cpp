// 0x80362C74 ScalarDecomp::GetVal(int, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; mr 29,5; lbz 5,0x1f(30); lwz 3,0x0(30); extsb 5,5; bl _s80362C74_0; lis 0,17200; stw 3,0x14(1); lis 9,-32702; lfd f13,0x2f20(9); stw 0,0x10(1); lfs f11,0x40(30); lfd f0,0x10(1); lfs f12,0x3c(30); fsub f0,f0,f13; frsp f0,f0; fmadds f0,f0,f12,f11; stfs f0,0x0(29); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80362C74_0();
extern "C" void f_80362C74() {}
