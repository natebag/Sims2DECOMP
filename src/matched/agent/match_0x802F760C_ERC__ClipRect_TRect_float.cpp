// 0x802F760C ERC::ClipRect(TRect<float> (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 9,0x70(30); li 4,0; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,3; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,54; stb 0,0x0(3); lfs f0,0x0(29); stfs f0,0x8(3); lfs f13,0x4(29); stfs f13,0xc(3); lfs f0,0x8(29); stfs f0,0x10(3); lfs f13,0xc(29); stfs f13,0x14(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F760C() {}
