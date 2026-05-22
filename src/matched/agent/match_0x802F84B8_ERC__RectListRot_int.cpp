// 0x802F84B8 ERC::RectListRot(int, (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 28,0x8(1); stw 0,0x24(1); mr 31,3; mr 30,5; mr 29,6; fmr f31,f1; mr. 28,4; beq 0f; mr 4,30; rlwinm 5,28,6,0,25; bl _s802F84B8_0; lwz 9,0x70(31); mr 30,3; li 4,0; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,4; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,59; sth 28,0x2(3); stb 0,0x0(3); stw 30,0x4(3); lfs f0,0x0(29); stfs f0,0x8(3); lfs f13,0x4(29); stfs f13,0xc(3); lfs f0,0x8(29); stfs f0,0x10(3); lfs f13,0xc(29); stfs f31,0x18(3); stfs f13,0x14(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x8(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802F84B8_0();
extern "C" void f_802F84B8() {}
