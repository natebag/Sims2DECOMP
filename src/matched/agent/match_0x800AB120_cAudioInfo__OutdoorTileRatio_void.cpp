// 0x800AB120 cAudioInfo::OutdoorTileRatio(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 25,0x2c(1); stw 0,0x4c(1); addi 3,1,8; li 4,0; li 5,0; li 6,1; bl _s800AB120_0; li 26,0; li 25,0; li 27,0; addi 30,1,16; 0:; mr 3,30; addi 4,1,8; bl _s800AB120_1; addi 28,27,1; mr 31,30; li 29,32; 1:; lwz 3,-21488(13); mr 4,30; lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 3f; lwz 3,-21488(13); mr 4,30; lwz 9,0x0(3); lha 0,0x108(9); lwz 9,0x10c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 2f; addi 26,26,1; b 3f; 2:; addi 25,25,1; 3:; mr 3,31; bl _s800AB120_2; addi 4,3,1; mr 3,31; bl _s800AB120_3; mr 3,31; bl _s800AB120_4; addi 4,3,1; mr 3,31; bl _s800AB120_5; addic. 29,29,-1; bne 1b; addi 3,1,8; bl _s800AB120_6; rlwinm 0,27,0,31,31; add 4,3,0; mr 27,28; addi 3,1,8; bl _s800AB120_7; addi 3,1,8; bl _s800AB120_8; rlwinm 0,28,0,31,31; add 4,3,0; addi 3,1,8; bl _s800AB120_9; mr 3,30; li 4,2; bl _s800AB120_10; cmpwi 27,32; blt 0b; xoris 0,26,32768; stw 0,0x24(1); lis 8,17200; add 0,25,26; mr 11,9; stw 8,0x20(1); xoris 0,0,32768; lis 10,-32706; lis 7,-32706; lfd f13,0x20(1); mr 30,9; stw 0,0x24(1); addi 3,1,8; lfd f12,-28008(10); li 4,2; stw 8,0x20(1); fsub f13,f13,f12; lfs f10,-28000(7); lfd f0,0x20(1); frsp f13,f13; fsub f0,f0,f12; frsp f0,f0; fdivs f13,f13,f0; fmuls f13,f13,f10; fmr f0,f13; fctiwz f11,f0; stfd f11,0x20(1); lwz 30,0x24(1); bl _s800AB120_11; mr 3,30; lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x2c(1); addi 1,1,72"
extern "C" void _s800AB120_0();
extern "C" void _s800AB120_1();
extern "C" void _s800AB120_2();
extern "C" void _s800AB120_3();
extern "C" void _s800AB120_4();
extern "C" void _s800AB120_5();
extern "C" void _s800AB120_6();
extern "C" void _s800AB120_7();
extern "C" void _s800AB120_8();
extern "C" void _s800AB120_9();
extern "C" void _s800AB120_10();
extern "C" void _s800AB120_11();
extern "C" void f_800AB120() {}
