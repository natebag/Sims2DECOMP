// 0x8024EAB0 LoadApploader (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-112(1); stw 31,0x6c(1); li 3,32; li 4,32; bl _s8024EAB0_0; mr 31,3; bl _s8024EAB0_1; mr 6,3; mr 4,31; addi 3,1,56; li 5,32; li 7,0; li 8,0; bl _s8024EAB0_2; b 0f; 0:; b 1f; 1:; b 3f; 2:; bl _s8024EAB0_3; cmpwi 3,0; bne 3f; li 3,0; bl _s8024EAB0_4; 3:; addi 3,1,56; bl _s8024EAB0_5; cmpwi 3,0; bne 2b; bl _s8024EAB0_6; lwz 4,0x14(31); addi 6,3,32; addi 3,1,8; addi 0,4,31; rlwinm 5,0,0,0,26; lis 4,-32480; li 7,0; li 8,0; bl _s8024EAB0_7; b 4f; 4:; b 5f; 5:; b 7f; 6:; bl _s8024EAB0_8; cmpwi 3,0; bne 7f; li 3,0; bl _s8024EAB0_9; 7:; addi 3,1,8; bl _s8024EAB0_10; cmpwi 3,0; bne 6b; lwz 4,0x14(31); lis 3,-32480; addi 0,4,31; rlwinm 4,0,0,0,26; bl _s8024EAB0_11; mr 3,31; lwz 0,0x74(1); lwz 31,0x6c(1); addi 1,1,112; mtspr 8,0"
extern "C" void _s8024EAB0_0();
extern "C" void _s8024EAB0_1();
extern "C" void _s8024EAB0_2();
extern "C" void _s8024EAB0_3();
extern "C" void _s8024EAB0_4();
extern "C" void _s8024EAB0_5();
extern "C" void _s8024EAB0_6();
extern "C" void _s8024EAB0_7();
extern "C" void _s8024EAB0_8();
extern "C" void _s8024EAB0_9();
extern "C" void _s8024EAB0_10();
extern "C" void _s8024EAB0_11();
extern "C" void f_8024EAB0() {}
