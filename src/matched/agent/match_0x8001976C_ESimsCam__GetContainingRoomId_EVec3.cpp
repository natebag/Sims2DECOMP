// 0x8001976C ESimsCam::GetContainingRoomId(EVec3 (660 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 24,0x18(1); stw 0,0x3c(1); lis 9,-32697; lwz 9,0x5e94(9); cmpwi 9,0; bne 0f; li 3,0; b 5f; 0:; lfs f0,0x50(9); lfs f12,0x4(4); mr 8,7; lfs f13,0x4c(9); lis 6,17200; fsubs f12,f12,f0; lfs f9,0x0(4); fmr f0,f12; mr 9,7; fctiwz f11,f0; lis 11,-32707; stfd f11,0x10(1); fsubs f9,f9,f13; fmr f0,f9; lfd f13,-7168(11); fctiwz f10,f0; lwz 26,0x14(1); stfd f10,0x10(1); lis 10,-32707; xoris 0,26,32768; lfs f11,-7160(10); lwz 31,0x14(1); stw 0,0x14(1); stw 6,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fsubs f12,f12,f0; fcmpu 0,f12,f11; cror 3,2,1; bns 1f; addi 26,26,1; 1:; xoris 0,31,32768; stw 0,0x14(1); stw 6,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fsubs f0,f9,f0; fcmpu 0,f0,f11; cror 3,2,1; bns 2f; addi 31,31,1; 2:; cmpwi 26,0; ble 3f; cmpwi 31,0; ble 3f; lwz 28,-21488(13); addi 3,1,8; mr 5,31; li 6,1; lwz 30,0x0(28); mr 4,26; lha 29,0xe8(30); addi 30,30,232; add 29,28,29; bl _s8001976C_0; lwz 0,0x4(30); addi 4,1,8; mr 3,29; mtspr 8,0; blrl; mr 25,3; li 4,2; addi 3,1,8; bl _s8001976C_1; lwz 29,0x0(28); addi 3,1,8; addi 5,31,1; li 6,1; lha 30,0xe8(29); mr 4,26; addi 29,29,232; add 30,28,30; bl _s8001976C_2; lwz 0,0x4(29); addi 4,1,8; mr 3,30; mtspr 8,0; blrl; mr 27,3; li 4,2; addi 3,1,8; bl _s8001976C_3; lwz 29,0x0(28); addi 3,1,8; addi 5,31,-1; li 6,1; lha 30,0xe8(29); mr 4,26; addi 29,29,232; add 30,28,30; bl _s8001976C_4; lwz 0,0x4(29); addi 4,1,8; mr 3,30; mtspr 8,0; blrl; mr 24,3; li 4,2; addi 3,1,8; bl _s8001976C_5; lwz 29,0x0(28); addi 3,1,8; mr 5,31; li 6,1; lha 30,0xe8(29); addi 4,26,1; addi 29,29,232; add 30,28,30; bl _s8001976C_6; lwz 0,0x4(29); addi 4,1,8; mr 3,30; mtspr 8,0; blrl; mr 29,3; li 4,2; addi 3,1,8; bl _s8001976C_7; lwz 30,0x0(28); mr 5,31; li 6,1; addi 3,1,8; lha 0,0xe8(30); addi 4,26,-1; addi 30,30,232; add 28,28,0; bl _s8001976C_8; lwz 0,0x4(30); addi 4,1,8; mr 3,28; mtspr 8,0; blrl; mr 31,3; li 4,2; addi 3,1,8; bl _s8001976C_9; cmpw 25,27; bne 3f; cmpw 25,24; bne 3f; cmpw 25,29; bne 3f; cmpw 25,31; beq 4f; 3:; li 3,0; ori 3,3,65531; b 5f; 4:; mr 3,25; 5:; lwz 0,0x3c(1); mtspr 8,0; lmw 24,0x18(1); addi 1,1,56"
extern "C" void _s8001976C_0();
extern "C" void _s8001976C_1();
extern "C" void _s8001976C_2();
extern "C" void _s8001976C_3();
extern "C" void _s8001976C_4();
extern "C" void _s8001976C_5();
extern "C" void _s8001976C_6();
extern "C" void _s8001976C_7();
extern "C" void _s8001976C_8();
extern "C" void _s8001976C_9();
extern "C" void f_8001976C() {}
