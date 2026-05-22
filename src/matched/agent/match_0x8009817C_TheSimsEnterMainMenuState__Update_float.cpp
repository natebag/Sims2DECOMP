// 0x8009817C TheSimsEnterMainMenuState::Update(float) (1148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 26,0x50(1); stw 0,0x6c(1); lis 9,-32706; mr 31,3; lfs f0,-29644(9); lis 3,-32697; lwz 28,0xc(31); addi 3,3,23428; stfs f0,0xc(1); li 27,0; stfs f0,0x8(1); lis 26,-32697; bl _s8009817C_0; cmpwi 28,3; beq 5f; bgt 0f; cmpwi 28,1; beq 2f; bgt 4f; cmpwi 28,0; beq 1f; b 16f; 0:; cmpwi 28,5; beq 8f; blt 6f; cmpwi 28,6; beq 9f; b 16f; 1:; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); 2:; lwz 11,-22572(13); lis 4,100; ori 4,4,44053; lis 30,-32693; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,14155; ori 4,4,56554; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,1162; ori 4,4,59727; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,-13521; ori 4,4,42957; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,23913; ori 4,4,38587; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,10927; ori 4,4,62296; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,8494; ori 4,4,56612; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,-20864; ori 4,4,63784; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,-13004; ori 4,4,43996; lwz 9,0xd1c(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22572(13); lis 4,30424; ori 4,4,7210; lwz 9,0xd1c(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; lis 4,20498; addi 3,30,24536; ori 4,4,58880; bl _s8009817C_1; cmpwi 3,0; bne 3f; lis 4,20498; addi 3,30,24536; ori 4,4,58880; bl _s8009817C_2; b 10f; 3:; lwz 0,-21488(13); cmpwi 0,0; beq 10f; lwz 9,0xc(31); addi 9,9,3; b 11f; 4:; lis 3,-32693; lis 4,20498; addi 3,3,24536; ori 4,4,58880; bl _s8009817C_3; cmpwi 3,0; beq 12f; lis 11,-32697; stw 27,0x5f18(11); lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); 5:; addi 3,1,16; bl _s8009817C_4; addi 3,1,16; li 4,16; bl _s8009817C_5; lwz 30,-21480(13); addi 3,1,16; li 4,2; bl _s8009817C_6; cmpwi 30,0; beq 12f; bl _s8009817C_7; b 10f; 6:; addi 3,1,16; bl _s8009817C_8; addi 3,1,16; li 4,16; bl _s8009817C_9; lwz 30,-21480(13); addi 3,1,16; li 4,2; bl _s8009817C_10; cmpwi 30,0; beq 12f; lis 9,-32697; addi 30,9,24012; lwz 0,0x434(30); cmpwi 0,0; beq 7f; lwz 9,0x148(30); lwz 3,-21492(13); lbz 4,0x1c(9); extsb 4,4; bl _s8009817C_11; 7:; lis 9,-32706; lwz 4,0x340(30); lfs f0,-29640(9); addi 11,1,16; lwz 3,-26392(13); mr 5,11; stfs f0,0x10(1); stfs f0,0x4(11); bl _s8009817C_12; b 10f; 8:; lis 30,-32693; lis 29,-32706; addi 3,30,24536; addi 4,29,-29708; bl _s8009817C_13; cmpwi 3,0; beq 12f; addi 3,30,24536; addi 4,29,-29708; li 5,1; bl _s8009817C_14; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); 9:; lis 9,-32706; mr 3,31; lfs f1,-29644(9); li 4,7; li 27,1; bl _s8009817C_15; 10:; lwz 9,0xc(31); addi 9,9,1; 11:; stw 9,0xc(31); 12:; lis 9,-32697; addi 30,9,23428; lwz 0,0x114(30); andi. 9,0,4; beq 13f; andi. 9,0,8; bne 13f; andi. 9,0,2; bne 13f; lwz 11,-26532(13); lis 4,-32693; addi 4,4,-11760; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lfs f13,0x11c(30); lis 9,-32706; lfs f0,-29636(9); fsubs f1,f1,f13; fcmpu 7,f1,f0; mfcr 0; rlwinm 0,0,30,31,31; cmpwi 0,0; beq 13f; lwz 0,0x114(30); li 9,-14; and 0,0,9; ori 0,0,2; stw 0,0x114(30); 13:; lis 3,-32697; lis 30,-32706; lwz 6,0xc(31); addi 3,3,23428; mr 5,28; addi 4,30,-29696; bl _s8009817C_16; cmpwi 27,0; beq 16f; lwz 0,0x1c(31); cmpwi 0,0; bne 14f; lis 5,-32706; addi 3,26,23428; addi 4,30,-29696; addi 5,5,-29660; li 6,0; bl _s8009817C_17; b 15f; 14:; lis 5,-32706; addi 3,26,23428; addi 4,30,-29696; addi 5,5,-29652; li 6,0; bl _s8009817C_18; 15:; li 0,1; lwz 3,-21492(13); stw 0,0x1c(31); li 4,2; bl _s8009817C_19; 16:; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x50(1); addi 1,1,104"
extern "C" void _s8009817C_0();
extern "C" void _s8009817C_1();
extern "C" void _s8009817C_2();
extern "C" void _s8009817C_3();
extern "C" void _s8009817C_4();
extern "C" void _s8009817C_5();
extern "C" void _s8009817C_6();
extern "C" void _s8009817C_7();
extern "C" void _s8009817C_8();
extern "C" void _s8009817C_9();
extern "C" void _s8009817C_10();
extern "C" void _s8009817C_11();
extern "C" void _s8009817C_12();
extern "C" void _s8009817C_13();
extern "C" void _s8009817C_14();
extern "C" void _s8009817C_15();
extern "C" void _s8009817C_16();
extern "C" void _s8009817C_17();
extern "C" void _s8009817C_18();
extern "C" void _s8009817C_19();
extern "C" void f_8009817C() {}
