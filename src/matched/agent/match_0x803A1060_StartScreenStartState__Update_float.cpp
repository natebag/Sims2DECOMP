// 0x803A1060 StartScreenStartState::Update(float) (712 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 30,3; lwz 0,0x1c(30); cmpwi 0,0; bne 0f; lis 3,-32692; lis 4,32602; addi 3,3,-17444; ori 4,4,48173; bl _s803A1060_0; stw 3,0x1c(30); 0:; lwz 0,0x20(30); cmpwi 0,0; bne 1f; lis 3,-32697; addi 3,3,23428; bl _s803A1060_1; mr 4,3; lis 3,-32692; addi 3,3,-17444; bl _s803A1060_2; stw 3,0x20(30); 1:; bl _s803A1060_3; cmpwi 3,0; beq 3f; lis 9,-32697; addi 29,9,23428; lwz 0,0x114(29); andi. 9,0,4; beq 2f; andi. 9,0,8; bne 2f; andi. 9,0,2; bne 2f; lwz 11,-26532(13); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lfs f13,0x11c(29); lis 9,-32706; lfs f0,-30716(9); fsubs f1,f1,f13; fcmpu 7,f1,f0; mfcr 0; rlwinm 0,0,30,31,31; cmpwi 0,0; beq 2f; lwz 0,0x114(29); li 9,-14; and 0,0,9; ori 0,0,2; stw 0,0x114(29); 2:; lwz 9,-32160(13); lwz 0,0xb4(9); andi. 9,0,4; beq 7f; lis 9,-32706; lwz 3,0x8(30); lfs f1,-30712(9); li 4,6; bl _s803A1060_4; b 7f; 3:; lwz 9,-24644(13); lis 11,-32706; lfs f13,-26800(13); addi 11,11,-30904; lfs f0,0x34(9); lis 8,-32706; lwz 3,-26524(13); addi 8,8,-30912; fadds f0,f0,f13; li 4,38; stfs f0,0x34(9); addi 5,1,8; addi 6,1,16; li 7,1; lwz 9,0x0(11); lwz 10,0x4(11); lwz 11,0x0(8); lwz 12,0x4(8); stw 9,0x8(1); stw 10,0xc(1); li 8,0; li 9,0; stw 11,0x10(1); stw 12,0x14(1); bl _s803A1060_5; cmpwi 3,0; bne 4f; lis 9,-32697; lbz 0,0x6150(9); cmpwi 0,255; beq 5f; 4:; lwz 11,-24644(13); lis 9,-32706; lfs f13,-30708(9); lfs f0,0x34(11); fcmpu 0,f0,f13; cror 3,2,1; bns 5f; lis 3,-32706; addi 3,3,-30792; bl _s803A1060_6; 5:; mr 3,30; bl _s803A1060_7; cmpwi 3,0; beq 7f; mr 3,30; bl _s803A1060_8; cmpwi 3,1; bne 7f; mr 3,30; bl _s803A1060_9; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s803A1060_10; bl _s803A1060_11; stw 3,-31536(13); 6:; lwz 3,-31536(13); lis 4,14155; addi 28,1,24; ori 4,4,56554; bl _s803A1060_12; lwz 29,-26564(13); lis 4,-32706; li 5,0; addi 4,4,-30780; lwz 30,0x0(29); mr 3,28; lha 0,0x40(30); addi 30,30,64; add 29,29,0; bl _s803A1060_13; lwz 0,0x4(30); mr 3,29; mr 4,28; mtspr 8,0; blrl; lis 9,-32697; lwz 11,0x5f14(9); lis 6,17200; lwz 7,-26564(13); lis 9,-32706; lbz 0,0x1d(11); lis 8,-32706; lfd f0,-30704(9); extsb 0,0; lwz 9,0x0(7); xoris 0,0,32768; lfs f13,-30696(8); stw 0,0x34(1); lha 3,0x60(9); stw 6,0x30(1); lwz 0,0x64(9); add 3,7,3; lfd f1,0x30(1); mtspr 8,0; fsub f1,f1,f0; frsp f1,f1; fdivs f1,f1,f13; blrl; li 3,0; bl _s803A1060_14; 7:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72"
extern "C" void _s803A1060_0();
extern "C" void _s803A1060_1();
extern "C" void _s803A1060_2();
extern "C" void _s803A1060_3();
extern "C" void _s803A1060_4();
extern "C" void _s803A1060_5();
extern "C" void _s803A1060_6();
extern "C" void _s803A1060_7();
extern "C" void _s803A1060_8();
extern "C" void _s803A1060_9();
extern "C" void _s803A1060_10();
extern "C" void _s803A1060_11();
extern "C" void _s803A1060_12();
extern "C" void _s803A1060_13();
extern "C" void _s803A1060_14();
extern "C" void f_803A1060() {}
