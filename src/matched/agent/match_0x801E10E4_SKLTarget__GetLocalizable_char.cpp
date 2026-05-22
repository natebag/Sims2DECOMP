// 0x801E10E4 SKLTarget::GetLocalizable(char (808 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 28,3; lbz 3,0x0(31); extsb 3,3; bl _s801E10E4_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,8192; bl _s801E10E4_1; mr 29,3; li 0,0; sth 0,0x0(29); lwz 30,0xa4(28); cmpwi 30,0; beq 7f; lwz 3,-29536(13); mr 4,31; bl _s801E10E4_2; cmpwi 3,0; bne 1f; lwz 9,0x4(30); li 4,10; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_3; stw 30,0xa8(28); b 7f; 1:; lwz 3,-29524(13); mr 4,31; bl _s801E10E4_4; cmpwi 3,0; bne 2f; lwz 9,0x4(30); li 4,12; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_5; stw 30,0xac(28); b 7f; 2:; lwz 3,-29512(13); mr 4,31; bl _s801E10E4_6; cmpwi 3,0; bne 3f; lwz 9,0x4(30); li 4,11; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_7; stw 30,0xb0(28); b 7f; 3:; lwz 3,-29500(13); mr 4,31; bl _s801E10E4_8; cmpwi 3,0; bne 4f; lwz 9,0x4(30); li 4,17; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_9; stw 30,0xb4(28); b 7f; 4:; lwz 3,-29488(13); mr 4,31; bl _s801E10E4_10; cmpwi 3,0; bne 5f; lwz 9,0x4(30); li 4,18; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_11; stw 30,0xb8(28); b 7f; 5:; lwz 3,-29476(13); mr 4,31; bl _s801E10E4_12; cmpwi 3,0; bne 6f; lwz 9,0x4(30); li 4,15; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_13; stw 30,0xbc(28); b 7f; 6:; lwz 3,-29464(13); mr 4,31; bl _s801E10E4_14; cmpwi 3,0; bne 7f; lwz 9,0x4(30); li 4,9; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lis 0,20971; mr 30,3; ori 0,0,34079; srawi 3,30,31; mulhw 0,30,0; mr 4,29; srawi 0,0,5; subf 3,3,0; bl _s801E10E4_15; stw 30,0xc0(28); 7:; mr 3,29; bl _s801E10E4_16; mr 3,29; bl _s801E10E4_17; mr 3,29; bl _s801E10E4_18; mr 3,29; bl _s801E10E4_19; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801E10E4_20; mr 30,3; mr 4,29; bl _s801E10E4_21; mr 3,29; bl _s801E10E4_22; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801E10E4_0();
extern "C" void _s801E10E4_1();
extern "C" void _s801E10E4_2();
extern "C" void _s801E10E4_3();
extern "C" void _s801E10E4_4();
extern "C" void _s801E10E4_5();
extern "C" void _s801E10E4_6();
extern "C" void _s801E10E4_7();
extern "C" void _s801E10E4_8();
extern "C" void _s801E10E4_9();
extern "C" void _s801E10E4_10();
extern "C" void _s801E10E4_11();
extern "C" void _s801E10E4_12();
extern "C" void _s801E10E4_13();
extern "C" void _s801E10E4_14();
extern "C" void _s801E10E4_15();
extern "C" void _s801E10E4_16();
extern "C" void _s801E10E4_17();
extern "C" void _s801E10E4_18();
extern "C" void _s801E10E4_19();
extern "C" void _s801E10E4_20();
extern "C" void _s801E10E4_21();
extern "C" void _s801E10E4_22();
extern "C" void f_801E10E4() {}
