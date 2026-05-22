// 0x80029890 EIFenceWall::EIFenceWall(TileWallsSegment (772 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; stmw 24,0x90(1); stw 0,0xb4(1); mr 31,3; mr 26,4; mr 28,5; mr 30,6; bl _s80029890_0; lwz 11,-32640(13); lis 9,-32698; addi 9,9,-20536; addi 3,31,808; stw 9,0x0(31); addi 11,11,1; stw 11,-32640(13); mr 4,28; bl _s80029890_1; lwz 0,0x0(26); li 9,0; cmpwi 0,16; beq 0f; cmpwi 0,32; bne 1f; 0:; li 9,1; 1:; li 4,0; cmpwi 30,12; beq 3f; bgt 2f; cmpwi 30,2; beq 5f; b 6f; 2:; cmpwi 30,13; beq 4f; cmpwi 30,14; beq 5f; b 6f; 3:; lis 4,-12097; cmpwi 9,0; ori 4,4,50738; beq 6f; lis 4,-27479; ori 4,4,26800; b 6f; 4:; lis 4,16030; cmpwi 9,0; ori 4,4,26734; beq 6f; lis 4,21500; ori 4,4,9740; b 6f; 5:; lis 4,-11254; cmpwi 9,0; ori 4,4,19235; beq 6f; lis 4,-17301; ori 4,4,246; 6:; addi 30,1,96; li 6,0; li 7,0; li 5,0; mr 3,31; mr 27,30; bl _s80029890_2; li 0,0; addi 29,1,112; stw 0,0x3ac(31); addi 25,1,120; addi 24,1,128; lwz 3,0x0(26); bl _s80029890_3; lis 9,-32697; rlwinm 3,3,4,0,27; addi 9,9,22048; lis 7,-32697; lwzx 10,3,9; add 11,3,9; lwz 9,0x8(11); addi 3,1,8; lwz 8,0xc(11); lwz 0,0x4(11); stw 9,0x50(1); stw 10,0x48(1); stw 0,0x4c(1); stw 8,0x54(1); lwz 9,0x5e94(7); lfs f0,0x4c(9); stfs f0,0x58(1); lfs f13,0x50(9); stfs f13,0x5c(1); bl _s80029890_4; lis 9,-32707; lfs f0,0x50(1); lfs f1,0xd20(9); addi 3,1,8; fmuls f1,f0,f1; bl _s80029890_5; lbz 0,0x0(28); lbz 9,0x1(28); lis 7,17200; extsb 0,0; mr 8,11; xoris 0,0,32768; extsb 9,9; stw 0,0x8c(1); xoris 9,9,32768; lis 10,-32707; lfs f10,0x4c(1); stw 7,0x88(1); lis 6,-32707; lfd f11,0xd28(10); addi 3,1,8; lfd f13,0x88(1); mr 4,30; stw 9,0x8c(1); fsub f13,f13,f11; lfs f12,0x58(1); stw 7,0x88(1); frsp f13,f13; lfs f9,0x48(1); fadds f13,f13,f10; lfd f0,0x88(1); fadds f13,f13,f12; lfs f10,0x5c(1); fsub f0,f0,f11; lfs f12,0xd30(6); frsp f0,f0; stfs f13,0x60(1); fadds f0,f0,f9; fadds f0,f0,f10; stfs f0,0x64(1); stfs f12,0x8(30); bl _s80029890_6; li 0,4; addi 9,1,8; mtspr 9,0; 7:; lfs f0,0x0(9); lfs f13,0x4(9); stfs f0,0x4(9); stfs f13,0x0(9); addi 9,9,16; bdnz 7b; addi 4,1,8; mr 3,31; bl _s80029890_7; mr 3,27; bl _s80029890_8; mr 3,29; bl _s80029890_9; mr 5,29; mr 3,31; mr 4,27; bl _s80029890_10; mr 3,25; mr 4,27; crxor 6,6,6; bl _s80029890_11; mr 3,24; mr 4,29; crxor 6,6,6; bl _s80029890_12; li 4,1; mr 3,25; bl _s80029890_13; sth 3,0x358(31); li 4,1; mr 3,24; bl _s80029890_14; sth 3,0x35a(31); mr 3,31; bl _s80029890_15; lis 9,-32697; lwz 0,0x3ac(31); lwz 11,0x5e94(9); li 5,1; cmpwi 0,0; lwz 3,0x1c(11); bne 8f; li 5,0; 8:; mr 4,31; bl _s80029890_16; mr 3,29; li 4,2; bl _s80029890_17; mr 3,27; li 4,2; bl _s80029890_18; mr 3,31; lwz 0,0xb4(1); mtspr 8,0; lmw 24,0x90(1); addi 1,1,176"
extern "C" void _s80029890_0();
extern "C" void _s80029890_1();
extern "C" void _s80029890_2();
extern "C" void _s80029890_3();
extern "C" void _s80029890_4();
extern "C" void _s80029890_5();
extern "C" void _s80029890_6();
extern "C" void _s80029890_7();
extern "C" void _s80029890_8();
extern "C" void _s80029890_9();
extern "C" void _s80029890_10();
extern "C" void _s80029890_11();
extern "C" void _s80029890_12();
extern "C" void _s80029890_13();
extern "C" void _s80029890_14();
extern "C" void _s80029890_15();
extern "C" void _s80029890_16();
extern "C" void _s80029890_17();
extern "C" void _s80029890_18();
extern "C" void f_80029890() {}
