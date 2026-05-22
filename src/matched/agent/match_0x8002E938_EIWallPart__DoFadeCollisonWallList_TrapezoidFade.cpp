// 0x8002E938 EIWallPart::DoFadeCollisonWallList(TrapezoidFade (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stfd f29,0x40(1); stfd f30,0x48(1); stfd f31,0x50(1); stmw 25,0x24(1); stw 0,0x5c(1); lwz 30,0x0(5); lis 9,-32707; lfs f31,0xe68(9); li 27,0; cmpwi 30,0; lis 25,-32707; beq 6f; lis 9,-32707; fmr f29,f31; lfs f30,0xe6c(9); addi 29,1,8; addi 28,1,20; lis 26,-32693; 0:; lwz 31,0x0(30); lwz 0,0x3b0(31); cmpwi 0,0; beq 1f; lfs f31,0xe68(25); b 2f; 1:; lwz 11,0x3c(31); addi 9,31,60; lwz 0,0x4(9); addi 10,31,72; lwz 8,0x8(9); addi 3,26,3548; stw 11,0x8(1); mr 4,29; stw 0,0x4(29); stw 8,0x8(29); lwz 9,0x48(31); lwz 11,0x8(10); lwz 0,0x4(10); stw 9,0x14(1); stw 0,0x4(28); stw 11,0x8(28); bl _s8002E938_0; fmr f31,f1; 2:; bl _s8002E938_1; rlwinm 3,3,2,0,29; addi 9,31,932; stfsx f31,9,3; fcmpu 0,f31,f29; bne 3f; mr 3,31; li 4,0; li 5,0; bl _s8002E938_2; b 5f; 3:; fcmpu 0,f31,f30; li 27,1; li 4,2; ble 4f; li 4,1; 4:; mr 3,31; li 5,0; bl _s8002E938_3; 5:; lwz 30,0x8(30); cmpwi 30,0; bne 0b; 6:; mr 3,27; lwz 0,0x5c(1); mtspr 8,0; lmw 25,0x24(1); lfd f29,0x40(1); lfd f30,0x48(1); lfd f31,0x50(1); addi 1,1,88"
extern "C" void _s8002E938_0();
extern "C" void _s8002E938_1();
extern "C" void _s8002E938_2();
extern "C" void _s8002E938_3();
extern "C" void f_8002E938() {}
