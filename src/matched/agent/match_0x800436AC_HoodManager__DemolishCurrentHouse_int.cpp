// 0x800436AC HoodManager::DemolishCurrentHouse(int) (848 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; mfcr 12; stmw 22,0x90(1); stw 0,0xbc(1); stw 12,0x8c(1); addi 22,3,1; li 5,0; lwz 3,-32056(13); li 6,0; mr 4,22; li 28,0; bl _s800436AC_0; lwz 3,-32056(13); addi 26,1,128; mr 4,22; bl _s800436AC_1; lis 3,1; ori 3,3,24584; bl _s800436AC_2; bl _s800436AC_3; mr 24,3; lwz 4,-32056(13); bl _s800436AC_4; lwz 3,-32056(13); mr 4,22; bl _s800436AC_5; addis 30,24,1; lwz 0,0x6004(30); cmpw 28,0; bge 4f; li 27,1; li 29,0; 0:; addi 9,30,-32744; lwzx 9,9,29; addis 30,24,1; cmpwi 9,0; beq 3f; lwz 9,0x38(9); cmpwi 9,0; beq 3f; lha 9,0x12(9); cmpwi 9,11; bgt 1f; cmpwi 9,10; bge 3f; cmpwi 9,0; beq 2f; blt 3f; b 2f; 1:; cmpwi 9,15; beq 2f; ble 3f; cmpwi 9,34; bne 3f; 2:; addis 30,24,1; addi 9,30,-32744; lwzx 11,9,29; lwz 10,0x38(11); lwz 3,0x1c(10); bl _s800436AC_6; cmpwi 3,0; beq 3f; addi 9,30,-32740; stwx 27,9,29; 3:; lwz 0,0x6004(30); addi 28,28,1; addi 29,29,28; cmpw 28,0; blt 0b; 4:; addi 3,1,8; li 25,1; bl _s800436AC_7; cmpwi 4,24,0; lwz 4,-32056(13); mr 7,26; lwz 5,-32032(13); addi 27,1,72; lha 6,-32036(13); lwz 3,-21496(13); lwz 31,-21488(13); bl _s800436AC_8; lwz 3,-21488(13); lwz 4,-32056(13); lwz 9,0x0(3); lwz 5,0x80(1); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; 5:; li 28,1; addi 23,25,1; b 10f; 6:; li 29,1; addi 26,28,1; b 9f; 7:; addi 30,1,64; mr 4,29; mr 5,28; mr 6,25; mr 3,30; bl _s800436AC_9; lwz 9,0x0(31); mr 4,30; lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,31,3; blrl; andi. 0,3,32; bne 8f; lwz 9,0x0(31); li 5,0; mr 4,30; lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,31,3; blrl; addi 4,1,8; mr 3,27; bl _s800436AC_10; lwz 9,0x0(31); mr 4,30; mr 5,27; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,31,3; mtspr 8,0; blrl; 8:; mr 3,30; li 4,2; bl _s800436AC_11; addi 29,29,1; 9:; lwz 9,0x0(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; addi 3,3,-1; cmpw 29,3; blt 7b; mr 28,26; 10:; lwz 9,0x0(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; addi 3,3,-1; cmpw 28,3; blt 6b; mr 25,23; cmpwi 25,1; ble 5b; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,11,3; blrl; lha 6,-32036(13); lwz 7,0x80(1); lwz 4,-32056(13); lwz 5,-32032(13); lwz 3,-21496(13); bl _s800436AC_12; lwz 9,0x0(31); lwz 4,-32056(13); lha 3,0x10(9); lwz 0,0x14(9); lwz 5,-32040(13); add 3,31,3; mtspr 8,0; blrl; lwz 4,-32056(13); mr 3,24; lwz 5,-32040(13); bl _s800436AC_13; lwz 3,-32056(13); mr 4,22; li 5,0; bl _s800436AC_14; lwz 3,-32056(13); mr 4,22; bl _s800436AC_15; beq cr4,11f; mr 3,24; li 4,3; bl _s800436AC_16; 11:; addi 3,1,8; li 4,2; bl _s800436AC_17; lwz 0,0xbc(1); lwz 12,0x8c(1); mtspr 8,0; lmw 22,0x90(1); mtcrf 8,12; addi 1,1,184"
extern "C" void _s800436AC_0();
extern "C" void _s800436AC_1();
extern "C" void _s800436AC_2();
extern "C" void _s800436AC_3();
extern "C" void _s800436AC_4();
extern "C" void _s800436AC_5();
extern "C" void _s800436AC_6();
extern "C" void _s800436AC_7();
extern "C" void _s800436AC_8();
extern "C" void _s800436AC_9();
extern "C" void _s800436AC_10();
extern "C" void _s800436AC_11();
extern "C" void _s800436AC_12();
extern "C" void _s800436AC_13();
extern "C" void _s800436AC_14();
extern "C" void _s800436AC_15();
extern "C" void _s800436AC_16();
extern "C" void _s800436AC_17();
extern "C" void f_800436AC() {}
