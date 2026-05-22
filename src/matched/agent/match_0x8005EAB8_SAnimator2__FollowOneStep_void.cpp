// 0x8005EAB8 SAnimator2::FollowOneStep(void) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 31,3; li 4,1; lwz 3,0x8(31); li 28,0; li 29,2; bl _s8005EAB8_0; lwz 3,0x8(31); bl _s8005EAB8_1; cmpwi 3,0; beq 0f; li 3,0; li 4,2; b 5f; 0:; lwz 0,0x10(31); cmpwi 0,1; beq 4f; bgt 1f; cmpwi 0,0; b 3f; 1:; cmpwi 0,2; bne 3f; lis 9,-32707; lfs f0,0x1c(31); lfs f10,0x471c(9); addi 30,1,8; lfs f13,0x20(31); fadds f0,f0,f10; mr 11,9; lwz 3,0xc(31); fctiwz f12,f0; mr 4,30; stfd f12,0x18(1); fadds f13,f13,f10; li 5,-1; lwz 9,0x1c(1); fctiwz f11,f13; stfd f11,0x18(1); li 28,0; stw 9,0x4(30); li 29,1; lwz 11,0x1c(1); stw 11,0x8(1); bl _s8005EAB8_2; mr 3,31; bl _s8005EAB8_3; mr 25,3; mr 3,31; bl _s8005EAB8_4; lwz 9,0x4(31); mr 26,3; lwz 10,0x0(9); lwz 11,0x4(10); lwz 0,0x354(11); lha 3,0x350(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x4(31); mr 27,3; mr 4,30; mr 5,27; lwz 11,0x0(9); li 6,0; li 7,0; lwz 9,0x4(11); lha 3,0x130(9); lwz 0,0x134(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; stw 25,0x4(30); li 28,0; stw 26,0x8(1); li 29,0; lwz 9,0x0(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 9,0x4(31); mr 4,30; mr 5,27; li 6,0; lwz 11,0x0(9); li 7,0; lwz 9,0x4(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; lfs f1,0x30(3); bl _s8005EAB8_5; b 4f; 3:; li 28,0; li 29,0; 4:; mr 3,28; mr 4,29; 5:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s8005EAB8_0();
extern "C" void _s8005EAB8_1();
extern "C" void _s8005EAB8_2();
extern "C" void _s8005EAB8_3();
extern "C" void _s8005EAB8_4();
extern "C" void _s8005EAB8_5();
extern "C" void f_8005EAB8() {}
