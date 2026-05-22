// 0x8024129C cosf (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lfs f2,-28220(13); fmr f0,f1; stfs f0,0x10(1); lwz 9,0x10(1); rlwinm 9,9,0,1,31; lis 0,16201; ori 0,0,4056; cmpw 9,0; bgt 0f; bl _s8024129C_0; b 7f; 0:; lis 0,32639; ori 0,0,65535; cmpw 9,0; ble 1f; fsubs f1,f1,f1; b 7f; 1:; addi 3,1,8; bl _s8024129C_1; rlwinm 3,3,0,30,31; cmpwi 3,1; beq 4f; bgt 2f; cmpwi 3,0; beq 3f; b 6f; 2:; cmpwi 3,2; beq 5f; b 6f; 3:; lfs f1,0x8(1); lfs f2,0xc(1); bl _s8024129C_2; b 7f; 4:; lfs f1,0x8(1); li 3,1; lfs f2,0xc(1); bl _s8024129C_3; fneg f1,f1; b 7f; 5:; lfs f1,0x8(1); lfs f2,0xc(1); bl _s8024129C_4; fneg f1,f1; b 7f; 6:; lfs f1,0x8(1); li 3,1; lfs f2,0xc(1); bl _s8024129C_5; 7:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s8024129C_0();
extern "C" void _s8024129C_1();
extern "C" void _s8024129C_2();
extern "C" void _s8024129C_3();
extern "C" void _s8024129C_4();
extern "C" void _s8024129C_5();
extern "C" void f_8024129C() {}
