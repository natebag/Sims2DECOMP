// 0x8006AC98 SAnimator2::getSidestepSkillIDs(AnimRef (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32707; mr 31,3; lfs f0,0x4d34(9); mr 30,4; li 29,1; li 0,1; fcmpu 0,f1,f0; blt 0f; lis 9,-32707; lfs f0,0x4d38(9); fcmpu 0,f1,f0; ble 1f; 0:; li 29,0; 1:; lis 9,-32707; lfs f0,0x4d3c(9); fcmpu 0,f1,f0; ble 2f; li 0,0; 2:; cmpwi 0,1; bne 4f; lwz 3,0x4(31); li 4,40; bl _s8006AC98_0; cmpwi 29,1; bne 3f; lwz 3,0x4(31); mr 5,30; li 4,42; bl _s8006AC98_1; b 6f; 3:; lwz 3,0x4(31); mr 5,30; li 4,44; bl _s8006AC98_2; b 6f; 4:; lwz 3,0x4(31); li 4,39; bl _s8006AC98_3; cmpwi 29,1; bne 5f; lwz 3,0x4(31); mr 5,30; li 4,41; bl _s8006AC98_4; b 6f; 5:; lwz 3,0x4(31); mr 5,30; li 4,43; bl _s8006AC98_5; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8006AC98_0();
extern "C" void _s8006AC98_1();
extern "C" void _s8006AC98_2();
extern "C" void _s8006AC98_3();
extern "C" void _s8006AC98_4();
extern "C" void _s8006AC98_5();
extern "C" void f_8006AC98() {}
