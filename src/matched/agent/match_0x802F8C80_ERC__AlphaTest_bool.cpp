// 0x802F8C80 ERC::AlphaTest(bool, (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f31,0x30(1); stmw 27,0x1c(1); stw 0,0x3c(1); mr 30,3; mr 28,4; lwz 9,0x70(30); mr 27,5; li 5,0; li 4,0; lwz 0,0x2b4(9); fmr f31,f1; lha 3,0x2b0(9); mr 29,6; mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; lis 9,-32702; lfs f13,-3236(9); li 0,44; stw 29,0x4(3); fmuls f31,f31,f13; stb 0,0x0(3); stb 28,0x1(3); fctiwz f0,f31; stb 27,0x2(3); stfd f0,0x10(1); lwz 11,0x14(1); stb 11,0x3(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x1c(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void f_802F8C80() {}
