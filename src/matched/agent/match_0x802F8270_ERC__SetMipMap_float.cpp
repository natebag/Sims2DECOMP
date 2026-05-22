// 0x802F8270 ERC::SetMipMap(float, (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 9,0x70(30); li 4,0; li 5,0; fmr f31,f1; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,39; stfs f31,0x4(3); stb 0,0x0(3); stb 29,0x1(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void f_802F8270() {}
