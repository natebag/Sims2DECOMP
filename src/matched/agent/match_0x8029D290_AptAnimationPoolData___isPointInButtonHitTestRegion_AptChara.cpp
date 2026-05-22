// 0x8029D290 AptAnimationPoolData::_isPointInButtonHitTestRegion(AptCharacterButton (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stfd f30,0x80(1); stfd f31,0x88(1); stmw 25,0x64(1); stw 0,0x94(1); xoris 6,6,32768; stw 6,0x5c(1); lis 0,17200; mr 10,11; xoris 7,7,32768; stw 0,0x58(1); lis 9,-32703; lfd f13,-30192(9); mr 31,4; lfd f0,0x58(1); mr 27,5; stw 7,0x5c(1); addi 3,1,8; fsub f0,f0,f13; lfs f9,0x4(31); stw 0,0x58(1); frsp f31,f0; lfs f10,0x8(31); addi 5,1,24; lfd f0,0x58(1); mr 4,27; lfs f12,0xc(31); lfs f11,0x10(31); fsub f0,f0,f13; frsp f30,f0; stfs f9,0x8(1); stfs f10,0xc(1); stfs f12,0x10(1); stfs f11,0x14(1); bl _s8029D290_0; addi 3,1,16; mr 4,27; addi 5,1,32; bl _s8029D290_1; lfs f0,0x18(1); lfs f13,0x20(1); fcmpu 0,f0,f13; cror 3,2,0; bso 0f; stfs f0,0x20(1); stfs f13,0x18(1); 0:; lfs f0,0x1c(1); lfs f13,0x24(1); fcmpu 0,f0,f13; cror 3,2,0; bso 1f; stfs f0,0x24(1); stfs f13,0x1c(1); 1:; lwz 0,0x14(31); li 26,0; cmpw 26,0; bge 4f; addi 25,1,40; li 28,0; 2:; lwz 30,0x20(31); mr 4,27; lwz 29,0x1c(31); mr 5,25; lhax 3,30,28; add 30,30,28; rlwinm 3,3,3,0,28; add 3,29,3; bl _s8029D290_2; lha 3,0x2(30); addi 5,1,48; mr 4,27; rlwinm 3,3,3,0,28; add 3,29,3; bl _s8029D290_3; lha 3,0x4(30); mr 4,27; addi 5,1,56; rlwinm 3,3,3,0,28; add 3,29,3; bl _s8029D290_4; mr 3,25; fmr f1,f31; fmr f2,f30; bl _s8029D290_5; cmpwi 3,0; beq 3f; li 3,1; b 5f; 3:; lwz 0,0x14(31); addi 26,26,1; addi 28,28,6; cmpw 26,0; blt 2b; 4:; li 3,0; 5:; lwz 0,0x94(1); mtspr 8,0; lmw 25,0x64(1); lfd f30,0x80(1); lfd f31,0x88(1); addi 1,1,144"
extern "C" void _s8029D290_0();
extern "C" void _s8029D290_1();
extern "C" void _s8029D290_2();
extern "C" void _s8029D290_3();
extern "C" void _s8029D290_4();
extern "C" void _s8029D290_5();
extern "C" void f_8029D290() {}
