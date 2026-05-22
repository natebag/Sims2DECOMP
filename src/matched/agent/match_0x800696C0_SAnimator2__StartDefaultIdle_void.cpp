// 0x800696C0 SAnimator2::StartDefaultIdle(void) (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; bl _s800696C0_0; mr 29,3; mr 3,31; bl _s800696C0_1; lbz 0,0x5fa(31); mr 30,3; cmpwi 0,0; beq 0f; cmpw 30,0; beq 0f; mr 3,31; bl _s800696C0_2; 0:; rlwinm 0,30,0,24,31; stb 30,0x5fa(31); cmpwi 0,0; beq 2f; lbz 0,0x5fb(31); cmpwi 0,0; beq 1f; mr 3,31; bl _s800696C0_3; 1:; mr 3,31; bl _s800696C0_4; lwz 0,0x61c(31); andis. 9,0,16; bne 4f; 2:; lwz 3,0x4(31); addi 5,1,8; mr 4,29; bl _s800696C0_5; lwz 9,0x8(1); li 4,1; lwz 3,0x8(31); li 6,-1; lwz 5,0x0(9); li 7,0; lfs f1,-32332(13); addi 3,3,820; bl _s800696C0_6; mr. 30,3; beq 3f; lwz 3,0x8(31); mr 4,30; lfs f1,0xfc(31); addi 3,3,820; bl _s800696C0_7; li 0,0; stb 0,0xd(30); 3:; li 0,0; lwz 9,0x61c(31); stw 0,0xc8(31); lis 11,-32707; lwz 0,0x8(1); oris 9,9,1; lfs f0,0x4c2c(11); mr 3,31; stw 0,0xd4(31); stfs f0,0xd0(31); stw 9,0x61c(31); bl _s800696C0_8; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800696C0_0();
extern "C" void _s800696C0_1();
extern "C" void _s800696C0_2();
extern "C" void _s800696C0_3();
extern "C" void _s800696C0_4();
extern "C" void _s800696C0_5();
extern "C" void _s800696C0_6();
extern "C" void _s800696C0_7();
extern "C" void _s800696C0_8();
extern "C" void f_800696C0() {}
