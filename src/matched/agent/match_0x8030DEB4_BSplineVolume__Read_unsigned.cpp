// 0x8030DEB4 BSplineVolume::Read(unsigned (768 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stfd f31,0x60(1); stmw 18,0x28(1); stw 0,0x6c(1); mr 26,4; mr 31,3; addi 3,1,24; li 5,4; mr 18,26; bl _s8030DEB4_0; addi 26,26,4; lwz 0,0x18(1); cmpwi 0,0; bne 10f; mr 4,26; li 5,128; mr 3,31; addi 26,26,128; bl _s8030DEB4_1; mr 4,26; li 5,4; addi 3,31,128; addi 26,26,4; bl _s8030DEB4_2; mr 4,26; li 5,4; addi 3,31,132; addi 26,26,4; bl _s8030DEB4_3; mr 4,26; li 5,4; addi 3,31,136; addi 26,26,4; bl _s8030DEB4_4; mr 4,26; li 5,4; addi 3,31,140; addi 26,26,4; bl _s8030DEB4_5; mr 4,26; addi 3,31,144; li 5,4; addi 26,26,4; bl _s8030DEB4_6; lwz 4,0x90(31); cmpwi 4,1; ble 10f; lis 3,-32692; li 5,16; rlwinm 4,4,2,0,29; addi 3,3,-27556; bl _s8030DEB4_7; li 29,0; lwz 5,0x90(31); mr 0,3; stw 0,0x94(31); rlwinm 5,5,2,0,29; li 4,0; bl _s8030DEB4_8; lwz 0,0x90(31); cmpw 29,0; bge 1f; li 30,0; 0:; lwz 4,0x84(31); mr 3,31; lwz 5,0x88(31); li 7,6; lwz 6,0x8c(31); addi 29,29,1; bl _s8030DEB4_9; lwz 9,0x94(31); stwx 3,30,9; addi 30,30,4; lwz 0,0x90(31); cmpw 29,0; blt 0b; 1:; lwz 4,0x90(31); lis 3,-32692; li 5,16; addi 3,3,-27556; rlwinm 4,4,2,0,29; li 22,0; addi 4,4,-1; bl _s8030DEB4_10; lwz 5,0x90(31); mr 0,3; stw 0,0xa4(31); rlwinm 5,5,2,0,29; li 4,0; addi 5,5,-1; bl _s8030DEB4_11; lwz 0,0x90(31); cmpw 22,0; bge 9f; 2:; lwz 0,0x84(31); li 24,0; lwz 11,0x88(31); addi 19,22,1; cmpw 24,0; lwz 10,0x8c(31); bge 8f; 3:; li 9,0; addi 21,24,1; cmpw 9,11; bge 7f; lis 20,-32702; 4:; li 25,0; addi 23,9,1; cmpw 25,10; bge 6f; lfs f31,0x2b0(20); rlwinm 28,9,2,0,29; rlwinm 29,22,2,0,29; rlwinm 30,24,2,0,29; li 27,0; 5:; mr 4,26; addi 3,1,8; li 5,12; addi 25,25,1; bl _s8030DEB4_12; addi 26,26,12; lfs f0,0x8(1); lwz 9,0x94(31); mr 7,10; fmuls f0,f0,f31; mr 6,10; lwzx 11,29,9; fctiwz f13,f0; lwzx 8,30,11; stfd f13,0x20(1); lwzx 9,28,8; lwz 10,0x24(1); sthx 10,27,9; lwz 11,0x94(31); lfs f0,0xc(1); lwzx 9,29,11; fmuls f0,f0,f31; lwzx 11,30,9; fctiwz f12,f0; stfd f12,0x20(1); lwzx 9,28,11; lwz 7,0x24(1); add 9,27,9; sth 7,0x2(9); lwz 11,0x94(31); lfs f0,0x10(1); lwzx 9,29,11; fmuls f0,f0,f31; lwzx 11,30,9; fctiwz f11,f0; stfd f11,0x20(1); lwzx 9,28,11; lwz 6,0x24(1); add 9,27,9; sth 6,0x4(9); addi 27,27,6; lwz 0,0x8c(31); cmpw 25,0; blt 5b; 6:; lwz 0,0x88(31); mr 9,23; lwz 10,0x8c(31); mr 11,0; cmpw 9,0; blt 4b; 7:; lwz 0,0x84(31); mr 24,21; cmpw 24,0; blt 3b; 8:; lwz 0,0x90(31); mr 22,19; cmpw 22,0; blt 2b; 9:; lwz 4,0x84(31); li 7,6; lwz 5,0x88(31); mr 3,31; lwz 6,0x8c(31); bl _s8030DEB4_13; stw 3,0x98(31); mr 3,31; bl _s8030DEB4_14; mr 3,31; bl _s8030DEB4_15; 10:; subf 3,18,26; lwz 0,0x6c(1); mtspr 8,0; lmw 18,0x28(1); lfd f31,0x60(1); addi 1,1,104"
extern "C" void _s8030DEB4_0();
extern "C" void _s8030DEB4_1();
extern "C" void _s8030DEB4_2();
extern "C" void _s8030DEB4_3();
extern "C" void _s8030DEB4_4();
extern "C" void _s8030DEB4_5();
extern "C" void _s8030DEB4_6();
extern "C" void _s8030DEB4_7();
extern "C" void _s8030DEB4_8();
extern "C" void _s8030DEB4_9();
extern "C" void _s8030DEB4_10();
extern "C" void _s8030DEB4_11();
extern "C" void _s8030DEB4_12();
extern "C" void _s8030DEB4_13();
extern "C" void _s8030DEB4_14();
extern "C" void _s8030DEB4_15();
extern "C" void f_8030DEB4() {}
