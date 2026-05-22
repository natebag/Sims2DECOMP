// 0x80362B50 ScalarDecomp::GetKeyframe(int, (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 30,3; mr 27,4; lwz 31,0x8(30); mr 26,5; lha 0,0x1c(30); lwz 9,0x4(30); cmpw 27,31; mullw 0,31,0; lwz 28,0xc(30); add 29,9,0; bge 1f; 0:; lbz 5,0x1e(30); mr 4,29; lwz 3,0x0(30); addi 31,31,-1; extsb 5,5; bl _s80362B50_0; lha 0,0x1c(30); addi 3,3,1; subf 28,3,28; cmpw 27,31; subf 29,0,29; blt 0b; 1:; cmpw 27,31; ble 3f; subf 31,31,27; 2:; lha 0,0x1c(30); lbz 5,0x1e(30); add 29,29,0; lwz 3,0x0(30); extsb 5,5; mr 4,29; bl _s80362B50_1; addi 3,3,1; addic. 31,31,-1; add 28,28,3; bne 2b; 3:; stw 28,0x4(26); lbz 0,0x1e(30); lbz 5,0x20(30); extsb 0,0; lwz 3,0x0(30); add 29,29,0; extsb 5,5; mr 4,29; bl _s80362B50_2; xoris 3,3,32768; stw 3,0xc(1); lis 0,17200; lis 11,-32702; lfs f12,0x24(30); stw 0,0x8(1); mr 3,30; lfd f13,0x2f18(11); mr 5,26; lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f12,f12,f0; stfs f12,0x8(26); lbz 4,0x20(30); extsb 4,4; add 4,29,4; bl _s80362B50_3; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"
extern "C" void _s80362B50_0();
extern "C" void _s80362B50_1();
extern "C" void _s80362B50_2();
extern "C" void _s80362B50_3();
extern "C" void f_80362B50() {}
