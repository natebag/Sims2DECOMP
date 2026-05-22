// 0x8009B288 UrbzModeNewGameState::Update(float) (1108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 27,0x54(1); stw 0,0x6c(1); lis 9,-32706; mr 31,3; lfs f0,-28628(9); lis 28,-32697; lwz 30,0xc(31); addi 3,28,23428; stfs f0,0xc(1); stfs f0,0x8(1); bl _s8009B288_0; cmpwi 30,5; beq 10f; bgt 1f; cmpwi 30,2; beq 6f; bgt 0f; cmpwi 30,0; beq 3f; cmpwi 30,1; beq 5f; b 20f; 0:; cmpwi 30,3; beq 7f; cmpwi 30,4; beq 8f; b 20f; 1:; cmpwi 30,8; beq 14f; bgt 2f; cmpwi 30,6; beq 11f; cmpwi 30,7; beq 13f; b 20f; 2:; cmpwi 30,9; beq 17f; cmpwi 30,10; beq 19f; b 20f; 3:; li 3,4; li 27,1; bl _s8009B288_1; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,-21492(13); li 4,3; bl _s8009B288_2; lis 9,-32697; addi 3,28,23428; addi 29,9,24012; li 4,0; stw 30,0x44c(29); stw 27,0x448(29); bl _s8009B288_3; addi 9,28,23428; lwz 0,0xf0(9); cmpwi 0,0; beq 4f; mr 3,29; bl _s8009B288_4; b 15f; 4:; stw 27,0x3e4(29); b 15f; 5:; li 0,5; addi 3,28,23428; stw 0,-24612(13); bl _s8009B288_5; b 15f; 6:; lwz 9,-24612(13); addi 9,9,-1; cmpwi 9,0; stw 9,-24612(13); bge 20f; lis 3,-32693; lis 4,-32706; addi 3,3,24536; addi 4,4,-28660; bl _s8009B288_6; b 15f; 7:; lis 30,-32693; lis 29,-32706; addi 3,30,24536; addi 4,29,-28660; bl _s8009B288_7; cmpwi 3,0; beq 20f; addi 3,30,24536; addi 4,29,-28660; li 5,1; bl _s8009B288_8; b 15f; 8:; lwz 3,-21476(13); li 4,1; lwz 9,0x0(3); lha 0,0x120(9); lwz 9,0x124(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 9f; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; 9:; addi 28,28,23428; lis 29,-32706; addi 30,28,244; mr 3,30; bl _s8009B288_9; lha 4,0x4(3); addi 3,29,-28644; bl _s8009B288_10; lis 3,-32697; addi 3,3,-7672; bl _s8009B288_11; stw 3,-24616(13); mr 3,30; bl _s8009B288_12; lha 30,0x4(3); addi 3,29,-28644; mr 4,30; bl _s8009B288_13; mr 3,28; mr 4,30; li 5,0; bl _s8009B288_14; li 3,1; bl _s8009B288_15; b 15f; 10:; addi 3,1,16; bl _s8009B288_16; addi 3,1,16; li 4,16; bl _s8009B288_17; lwz 30,-21480(13); addi 3,1,16; li 4,2; bl _s8009B288_18; cmpwi 30,0; beq 20f; addi 30,28,23428; lwz 3,0x3c(30); bl _s8009B288_19; lwz 3,0x3c(30); bl _s8009B288_20; b 15f; 11:; addi 28,28,23428; lwz 3,0x3c(28); bl _s8009B288_21; cmpwi 3,0; beq 20f; lwz 11,0x3c(28); cmpwi 11,0; beq 12f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 12:; li 0,0; lwz 4,-24616(13); lis 3,-32697; stw 0,0x3c(28); addi 3,3,-7672; bl _s8009B288_22; lwz 9,0xc(31); li 0,5; stw 0,-24612(13); b 16f; 13:; lwz 9,-24612(13); addi 9,9,-1; cmpwi 9,0; stw 9,-24612(13); bge 20f; lwz 9,0xc(31); li 0,5; stw 0,-24612(13); b 16f; 14:; lwz 9,-24612(13); addi 9,9,-1; cmpwi 9,0; stw 9,-24612(13); bge 20f; bl _s8009B288_23; lis 30,-32701; li 3,0; addi 4,30,27664; li 5,2; li 6,1; bl _s8009B288_24; addi 4,30,27664; li 3,1; li 5,2; li 6,1; bl _s8009B288_25; lwz 3,-32056(13); bl _s8009B288_26; 15:; lwz 9,0xc(31); 16:; addi 9,9,1; stw 9,0xc(31); b 20f; 17:; lwz 11,-21476(13); li 4,1; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; li 4,-1; lwz 9,0x0(30); lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); lwz 4,-32056(13); lwz 0,0x6c(9); lha 3,0x68(9); lwz 5,-32040(13); mtspr 8,0; add 3,30,3; blrl; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lwz 4,-32056(13); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; lwz 5,-32040(13); mtspr 8,9; blrl; addi 3,28,23428; bl _s8009B288_27; addi 3,28,23428; lwz 0,0xf0(3); cmpwi 0,0; beq 18f; lis 9,-32697; li 0,0; stw 0,0x6234(9); 18:; bl _s8009B288_28; lwz 9,0xc(31); addi 9,9,1; stw 9,0xc(31); 19:; lis 9,-32706; mr 3,31; lfs f1,-28628(9); li 4,13; bl _s8009B288_29; 20:; lwz 0,0x6c(1); mtspr 8,0; lmw 27,0x54(1); addi 1,1,104"
extern "C" void _s8009B288_0();
extern "C" void _s8009B288_1();
extern "C" void _s8009B288_2();
extern "C" void _s8009B288_3();
extern "C" void _s8009B288_4();
extern "C" void _s8009B288_5();
extern "C" void _s8009B288_6();
extern "C" void _s8009B288_7();
extern "C" void _s8009B288_8();
extern "C" void _s8009B288_9();
extern "C" void _s8009B288_10();
extern "C" void _s8009B288_11();
extern "C" void _s8009B288_12();
extern "C" void _s8009B288_13();
extern "C" void _s8009B288_14();
extern "C" void _s8009B288_15();
extern "C" void _s8009B288_16();
extern "C" void _s8009B288_17();
extern "C" void _s8009B288_18();
extern "C" void _s8009B288_19();
extern "C" void _s8009B288_20();
extern "C" void _s8009B288_21();
extern "C" void _s8009B288_22();
extern "C" void _s8009B288_23();
extern "C" void _s8009B288_24();
extern "C" void _s8009B288_25();
extern "C" void _s8009B288_26();
extern "C" void _s8009B288_27();
extern "C" void _s8009B288_28();
extern "C" void _s8009B288_29();
extern "C" void f_8009B288() {}
