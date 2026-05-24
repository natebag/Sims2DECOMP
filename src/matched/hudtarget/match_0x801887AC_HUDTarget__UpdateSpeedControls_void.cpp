// 0x801887AC HUDTarget::UpdateSpeedControls(void) (1096 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32697; mr 31,3; lwz 0,0x6254(9); cmpwi 0,0; bne 26f; lis 9,-32697; addi 26,9,23428; lwz 0,0xf0(26); cmpwi 0,0; bne 26f; lwz 30,-26524(13); li 4,0; mr 3,30; bl _s801887AC_0; mr 4,3; mr 3,30; bl _s801887AC_1; lwz 30,-26524(13); mr 28,3; li 4,1; mr 3,30; bl _s801887AC_2; mr 4,3; mr 3,30; bl _s801887AC_3; lbz 9,0xf5(31); mr 27,3; lwz 29,0xf8(31); mr 3,28; rlwinm 0,9,0,27,27; stb 9,0xf4(31); stb 0,0xf5(31); mr 4,29; bl _s801887AC_4; mr 30,3; mr 4,29; mr 3,28; bl _s801887AC_5; mr 6,3; mr 5,30; mr 3,28; li 4,34; li 7,0; bl _s801887AC_6; cmpwi 3,0; beq 0f; lbz 0,0xf5(31); ori 0,0,1; stb 0,0xf5(31); 0:; lwz 30,0xf8(31); mr 3,28; mr 4,30; bl _s801887AC_7; mr 29,3; mr 4,30; mr 3,28; bl _s801887AC_8; mr 6,3; mr 5,29; mr 3,28; li 4,35; li 7,0; bl _s801887AC_9; cmpwi 3,0; beq 1f; lbz 0,0xf5(31); ori 0,0,2; stb 0,0xf5(31); 1:; lwz 0,0xec(26); cmpwi 0,0; beq 3f; lwz 30,0xfc(31); mr 3,27; mr 4,30; bl _s801887AC_10; mr 29,3; mr 4,30; mr 3,27; bl _s801887AC_11; mr 6,3; mr 5,29; mr 3,27; li 4,34; li 7,0; bl _s801887AC_12; cmpwi 3,0; beq 2f; lbz 0,0xf5(31); ori 0,0,4; stb 0,0xf5(31); 2:; lwz 30,0xfc(31); mr 3,27; mr 4,30; bl _s801887AC_13; mr 29,3; mr 4,30; mr 3,27; bl _s801887AC_14; mr 6,3; mr 5,29; mr 3,27; li 4,35; li 7,0; bl _s801887AC_15; cmpwi 3,0; beq 4f; 3:; lbz 0,0xf5(31); ori 0,0,8; stb 0,0xf5(31); 4:; lis 9,-32697; lwz 11,0x5f14(9); lwz 0,0x10(11); cmpwi 0,0; beq 7f; lwz 0,0xf4(31); andis. 9,0,2056; andis. 0,0,514; xoris 9,9,8; subfic 11,9,0; adde 9,11,9; xoris 0,0,2; subfic 11,0,0; adde 0,11,0; or. 11,0,9; beq 7f; lbz 0,0xf5(31); andi. 9,0,16; beq 5f; andi. 0,0,239; b 6f; 5:; ori 0,0,16; 6:; stb 0,0xf5(31); 7:; lbz 0,0xf7(31); li 4,38; stb 0,0xf6(31); lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; mcrf cr7,cr0; blt cr7,11f; cmpwi 3,1; beq 10f; bgt 8f; beq cr7,9f; b 17f; 8:; cmpwi 3,2; beq 15f; b 17f; 9:; li 0,-4; b 16f; 10:; li 0,0; b 16f; 11:; lwz 3,-21484(13); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 9,-3; beq 12f; li 9,0; 12:; lbz 10,0xf5(31); stb 9,0xf7(31); andi. 0,10,5; cmpwi 0,0; beq 13f; li 0,-4; b 16f; 13:; extsb 0,9; cmpwi 0,-3; beq 17f; lis 9,-32697; lwz 11,0x5f14(9); lwz 0,0x10(11); cmpwi 0,0; beq 14f; andi. 0,10,16; beq 17f; b 15f; 14:; andi. 0,10,10; cmpwi 0,10; bne 17f; 15:; li 0,-2; 16:; stb 0,0xf7(31); 17:; lbz 9,0xf7(31); extsb 0,9; cmpwi 0,-4; bne 18f; lis 9,-32697; lwz 3,0x5bcc(9); bl _s801887AC_16; b 19f; 18:; addi 0,9,3; rlwinm 0,0,0,24,31; cmplwi 0,1; bgt 19f; lis 9,-32697; lwz 3,0x5bcc(9); bl _s801887AC_17; 19:; lbz 0,0xf6(31); lbz 9,0xf7(31); extsb 0,0; extsb 9,9; cmpw 0,9; beq 26f; cmpwi 9,-4; li 30,0; bne 20f; lis 30,23913; mr 3,31; ori 30,30,38587; li 4,0; bl _s801887AC_18; b 24f; 20:; cmpwi 0,-4; bne 21f; mr 3,31; li 4,0; bl _s801887AC_19; 21:; lbz 9,0xf7(31); mr 4,9; addi 9,9,3; rlwinm 9,9,0,24,31; cmplwi 9,1; bgt 22f; lis 30,-19609; ori 30,30,63383; b 23f; 22:; cmpwi 4,0; bne 23f; lbz 0,0xf6(31); lis 30,-7886; ori 30,30,30088; extsb 0,0; cmpwi 0,-2; bne 23f; lis 30,-21254; ori 30,30,54403; 23:; lwz 3,-21496(13); extsb 4,4; lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 24:; cmpwi 30,0; beq 26f; lwz 0,-31536(13); cmpwi 0,0; bne 25f; li 3,120; bl _s801887AC_20; bl _s801887AC_21; stw 3,-31536(13); 25:; lwz 3,-31536(13); mr 4,30; bl _s801887AC_22; 26:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s801887AC_0();
extern "C" void _s801887AC_1();
extern "C" void _s801887AC_2();
extern "C" void _s801887AC_3();
extern "C" void _s801887AC_4();
extern "C" void _s801887AC_5();
extern "C" void _s801887AC_6();
extern "C" void _s801887AC_7();
extern "C" void _s801887AC_8();
extern "C" void _s801887AC_9();
extern "C" void _s801887AC_10();
extern "C" void _s801887AC_11();
extern "C" void _s801887AC_12();
extern "C" void _s801887AC_13();
extern "C" void _s801887AC_14();
extern "C" void _s801887AC_15();
extern "C" void _s801887AC_16();
extern "C" void _s801887AC_17();
extern "C" void _s801887AC_18();
extern "C" void _s801887AC_19();
extern "C" void _s801887AC_20();
extern "C" void _s801887AC_21();
extern "C" void _s801887AC_22();

struct HUDTarget {
    void UpdateSpeedControls();
};

void HUDTarget::UpdateSpeedControls() {
}
