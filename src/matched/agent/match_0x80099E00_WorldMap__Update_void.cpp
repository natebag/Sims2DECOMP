// 0x80099E00 WorldMap::Update(void) (976 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 29,0x84(1); stw 0,0x94(1); mr 31,3; lwz 0,0x8(31); cmpwi 0,0; bne 1f; lwz 0,0x0(31); cmpwi 0,0; beq 0f; lis 3,-32696; lis 4,-17670; addi 3,3,32332; ori 4,4,49883; bl _s80099E00_0; cmpwi 3,0; stw 3,0x8(31); beq 19f; bl _s80099E00_1; mr 3,31; bl _s80099E00_2; 0:; lwz 0,0x8(31); cmpwi 0,0; beq 19f; 1:; lwz 0,0xc(31); cmpwi 0,0; bne 2f; lis 3,-32692; lis 4,26961; addi 3,3,-27556; ori 4,4,21689; bl _s80099E00_3; stw 3,0xc(31); 2:; lwz 0,0x10(31); cmpwi 0,0; bne 3f; lis 3,-32693; lis 4,1510; addi 3,3,11064; ori 4,4,29; bl _s80099E00_4; stw 3,0x10(31); 3:; lwz 0,0x14(31); cmpwi 0,0; bne 4f; lis 3,-32693; lis 4,26961; addi 3,3,21144; ori 4,4,21689; bl _s80099E00_5; stw 3,0x14(31); 4:; lwz 0,0x98(31); cmpwi 0,0; bne 5f; lis 3,-32697; addi 3,3,23428; bl _s80099E00_6; mr 4,3; lis 3,-32692; addi 3,3,-17444; bl _s80099E00_7; stw 3,0x98(31); 5:; lwz 0,0xc(31); cmpwi 0,0; beq 6f; lwz 0,0x10(31); cmpwi 0,0; beq 6f; lwz 0,0x14(31); cmpwi 0,0; beq 6f; lwz 29,0x90(31); cmpwi 29,0; bne 6f; bl _s80099E00_8; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s80099E00_9; mr 30,3; li 4,0; li 5,1216; bl _s80099E00_10; mr 3,30; bl _s80099E00_11; mr 0,3; li 5,0; lwz 3,0x8(31); mr 4,0; stw 0,0x94(31); stw 0,0x90(31); bl _s80099E00_12; lwz 11,0x94(31); lwz 4,0x8(31); lwz 9,0x0(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x94(31); lis 4,26961; li 6,0; ori 4,4,21689; addi 30,3,820; li 5,0; mr 7,30; bl _s80099E00_13; lwz 11,0x94(31); li 4,0; li 5,0; lwz 9,0x0(11); lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,11,3; blrl; lis 4,26961; mr 3,30; ori 4,4,21689; li 5,1; li 6,0; bl _s80099E00_14; lwz 11,0xc(31); lis 9,-32706; lfs f1,-29560(9); lis 4,1; lfs f0,0x88(11); lis 5,1510; mr 3,30; ori 4,4,255; stfs f0,0x58(30); ori 5,5,29; li 6,-1; li 7,0; bl _s80099E00_15; lis 9,-32706; stw 29,0x64(30); lfs f0,-29556(9); stw 31,0x68(30); stfs f0,0x54(30); 6:; lwz 0,0x94(31); cmpwi 0,0; beq 10f; lfs f0,-26800(13); addic. 3,0,820; stfs f0,-26796(13); beq 9f; lwz 0,0xd8(31); cmpwi 0,0; beq 7f; lis 9,-32706; lfs f1,-29556(9); b 8f; 7:; lis 9,-32706; lfs f1,-29552(9); 8:; bl _s80099E00_16; 9:; lwz 3,0x94(31); addi 4,31,156; bl _s80099E00_17; 10:; lis 9,-32697; lwz 0,0x5ee4(9); cmpwi 0,0; beq 14f; addic. 3,0,424; beq 13f; lwz 0,0xd8(31); cmpwi 0,0; beq 11f; lis 9,-32706; lfs f1,-29556(9); b 12f; 11:; lis 9,-32706; lfs f1,-29552(9); 12:; bl _s80099E00_18; 13:; lis 9,-32697; lwz 3,0x5ee4(9); bl _s80099E00_19; 14:; lwz 0,0xd8(31); cmpwi 0,0; beq 15f; lis 9,-32706; lfs f0,-26800(13); lfs f13,-29548(9); lfs f12,0xc0(31); fmuls f0,f0,f13; fmuls f13,f0,f12; b 16f; 15:; lis 9,-32706; lfs f13,-29552(9); 16:; lfs f0,0xbc(31); lis 9,-32706; lfs f12,-29544(9); addi 4,1,8; fadds f0,f0,f13; stfs f13,0xc4(31); stfs f0,0xbc(31); fcmpu 0,f0,f12; cror 3,2,1; bns 18f; fmr f13,f12; 17:; fsubs f0,f0,f13; fcmpu 0,f0,f13; cror 3,2,1; bso 17b; stfs f0,0xbc(31); 18:; lfs f13,0xbc(31); mr 7,11; lis 6,17200; fmr f0,f13; lis 9,-32706; fctiwz f12,f0; lfd f11,-29536(9); stfd f12,0x78(1); lis 10,-32706; lfs f10,-29528(10); fmr f1,f13; lwz 11,0x7c(1); li 8,0; lwz 3,0x8(31); xoris 0,11,32768; stw 8,0xd0(31); stw 0,0x7c(1); stw 11,0xc8(31); stw 6,0x78(1); lfd f0,0x78(1); fsub f0,f0,f11; frsp f0,f0; fsubs f13,f13,f0; fmuls f13,f13,f10; fctiwz f12,f13; stfd f12,0x78(1); lwz 9,0x7c(1); stw 9,0xcc(31); bl _s80099E00_20; lwz 3,0x8(31); bl _s80099E00_21; 19:; lwz 0,0x94(1); mtspr 8,0; lmw 29,0x84(1); addi 1,1,144"
extern "C" void _s80099E00_0();
extern "C" void _s80099E00_1();
extern "C" void _s80099E00_2();
extern "C" void _s80099E00_3();
extern "C" void _s80099E00_4();
extern "C" void _s80099E00_5();
extern "C" void _s80099E00_6();
extern "C" void _s80099E00_7();
extern "C" void _s80099E00_8();
extern "C" void _s80099E00_9();
extern "C" void _s80099E00_10();
extern "C" void _s80099E00_11();
extern "C" void _s80099E00_12();
extern "C" void _s80099E00_13();
extern "C" void _s80099E00_14();
extern "C" void _s80099E00_15();
extern "C" void _s80099E00_16();
extern "C" void _s80099E00_17();
extern "C" void _s80099E00_18();
extern "C" void _s80099E00_19();
extern "C" void _s80099E00_20();
extern "C" void _s80099E00_21();
extern "C" void f_80099E00() {}
