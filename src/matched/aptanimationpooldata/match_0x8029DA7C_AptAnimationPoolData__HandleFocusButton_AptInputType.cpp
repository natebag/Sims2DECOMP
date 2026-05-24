// 0x8029DA7C AptAnimationPoolData::HandleFocusButton(AptInputType, (1320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); li 0,0; mr 25,6; stw 0,0x0(25); lwz 0,0x64(3); cmpwi 0,0; beq 35f; cmpwi 5,0; bne 35f; cmpwi 4,2; beq 4f; bgt 0f; cmpwi 4,1; beq 3f; b 35f; 0:; cmpwi 4,14; beq 1f; cmpwi 4,15; beq 2f; b 35f; 1:; lis 9,-32694; addi 9,9,-11332; addi 4,9,76; b 5f; 2:; lis 9,-32694; addi 9,9,-11332; addi 4,9,12; b 5f; 3:; lis 9,-32694; addi 9,9,-11332; addi 4,9,40; b 5f; 4:; lis 9,-32694; addi 9,9,-11332; addi 4,9,52; 5:; lwz 11,0x64(3); lwz 27,0x48(11); lwz 9,0x4c(27); lwz 3,0xc(9); bl _s8029DA7C_0; mr. 31,3; beq 35f; lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,1; beq 6f; cmpwi 0,42; bne 7f; 6:; andis. 0,9,2048; beq 7f; li 11,1; 7:; cmpwi 11,0; beq 21f; lis 11,-32700; mr 5,31; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); addi 9,9,1; sth 9,-6476(11); lwz 0,0x0(31); rlwinm 0,0,0,25,31; cmpwi 0,1; beq 8f; lwz 5,0x24(31); 8:; addi 5,5,12; mr 3,27; li 4,0; addi 6,1,16; addi 7,1,8; bl _s8029DA7C_1; lwz 30,0x10(1); cmpwi 30,0; beq 20f; lwz 9,0x8(1); lhz 0,0x2(9); cmpwi 0,0; bne 15f; mr 3,30; li 29,0; bl _s8029DA7C_2; cmpwi 3,14; bne 9f; mr 3,30; bl _s8029DA7C_3; subfic 0,3,0; adde 29,0,3; 9:; cmpwi 29,0; bne 14f; mr 3,30; li 28,0; bl _s8029DA7C_4; li 29,0; cmpwi 3,13; bne 10f; mr 3,30; bl _s8029DA7C_5; subfic 0,3,0; adde 29,0,3; 10:; cmpwi 29,0; bne 12f; mr 3,30; li 29,0; bl _s8029DA7C_6; cmpwi 3,18; bne 11f; mr 3,30; bl _s8029DA7C_7; subfic 0,3,0; adde 29,0,3; 11:; cmpwi 29,0; beq 13f; 12:; li 28,1; 13:; cmpwi 28,0; beq 15f; 14:; stw 30,0x0(25); b 20f; 15:; lwz 9,0x8(1); lhz 0,0x2(9); cmpwi 0,0; ble 20f; mr 3,30; li 28,0; bl _s8029DA7C_8; li 29,0; cmpwi 3,13; bne 16f; mr 3,30; bl _s8029DA7C_9; subfic 0,3,0; adde 29,0,3; 16:; cmpwi 29,0; bne 18f; mr 3,30; li 29,0; bl _s8029DA7C_10; cmpwi 3,18; bne 17f; mr 3,30; bl _s8029DA7C_11; subfic 0,3,0; adde 29,0,3; 17:; cmpwi 29,0; beq 19f; 18:; li 28,1; 19:; cmpwi 28,0; beq 20f; lwz 9,0x4c(30); addi 4,1,8; lwz 3,0xc(9); bl _s8029DA7C_12; mr. 3,3; beq 20f; mr 31,3; 20:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 21f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029DA7C_13; 21:; lwz 0,0x0(31); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-43; cmplwi 9,2; bgt 22f; rlwinm 11,0,5,31,31; 22:; cmpwi 11,0; beq 26f; lis 28,-32694; addi 29,1,20; addi 26,28,-16032; mr 4,29; mr 3,26; bl _s8029DA7C_14; mr 30,3; mr 5,31; mr 4,27; mr 3,26; li 6,0; bl _s8029DA7C_15; mr 4,30; mr 5,29; mr 3,26; bl _s8029DA7C_16; lwz 11,-16032(28); li 10,0; lwz 0,0x8(26); rlwinm 9,11,2,0,29; add 9,9,0; lwz 31,-4(9); lwz 0,0x0(31); rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 23f; rlwinm 10,0,5,31,31; 23:; cmpwi 10,0; beq 24f; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,-30096; lha 3,0x8(9); addi 5,5,-30280; lwz 0,0xc(9); li 6,1301; add 3,31,3; mtspr 8,0; blrl; lwz 9,-16032(28); cmpwi 9,0; ble 27f; lwz 0,0x8(26); rlwinm 9,9,2,0,29; lis 4,-32703; lis 5,-32703; add 9,9,0; addi 4,4,-30492; lwz 11,-4(9); addi 5,5,-30644; li 6,160; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,-16032(28); addi 9,9,-1; stw 9,-16032(28); b 27f; 24:; cmpwi 11,0; ble 25f; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,-30492; lha 3,0x10(9); addi 5,5,-30644; lwz 0,0x14(9); li 6,160; add 3,31,3; mtspr 8,0; blrl; lwz 9,-16032(28); addi 9,9,-1; stw 9,-16032(28); 25:; li 3,1; b 36f; 26:; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,-30096; lha 3,0x8(9); addi 5,5,-30280; lwz 0,0xc(9); li 6,1313; add 3,31,3; mtspr 8,0; blrl; 27:; mr 3,31; li 30,0; bl _s8029DA7C_17; cmpwi 3,14; bne 28f; mr 3,31; bl _s8029DA7C_18; subfic 0,3,0; adde 30,0,3; 28:; cmpwi 30,0; bne 33f; mr 3,31; li 29,0; bl _s8029DA7C_19; li 30,0; cmpwi 3,13; bne 29f; mr 3,31; bl _s8029DA7C_20; subfic 0,3,0; adde 30,0,3; 29:; cmpwi 30,0; bne 31f; mr 3,31; li 30,0; bl _s8029DA7C_21; cmpwi 3,18; bne 30f; mr 3,31; bl _s8029DA7C_22; subfic 0,3,0; adde 30,0,3; 30:; cmpwi 30,0; beq 32f; 31:; li 29,1; 32:; cmpwi 29,0; beq 34f; 33:; lwz 3,-23008(13); mr 4,31; bl _s8029DA7C_23; cmpwi 3,0; bne 34f; stw 31,0x0(25); 34:; lwz 9,0x8(31); lis 4,-32703; lis 5,-32703; addi 4,4,-30096; lha 3,0x10(9); addi 5,5,-30280; lwz 0,0x14(9); li 6,1321; add 3,31,3; mtspr 8,0; blrl; 35:; li 3,0; 36:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s8029DA7C_0();
extern "C" void _s8029DA7C_1();
extern "C" void _s8029DA7C_2();
extern "C" void _s8029DA7C_3();
extern "C" void _s8029DA7C_4();
extern "C" void _s8029DA7C_5();
extern "C" void _s8029DA7C_6();
extern "C" void _s8029DA7C_7();
extern "C" void _s8029DA7C_8();
extern "C" void _s8029DA7C_9();
extern "C" void _s8029DA7C_10();
extern "C" void _s8029DA7C_11();
extern "C" void _s8029DA7C_12();
extern "C" void _s8029DA7C_13();
extern "C" void _s8029DA7C_14();
extern "C" void _s8029DA7C_15();
extern "C" void _s8029DA7C_16();
extern "C" void _s8029DA7C_17();
extern "C" void _s8029DA7C_18();
extern "C" void _s8029DA7C_19();
extern "C" void _s8029DA7C_20();
extern "C" void _s8029DA7C_21();
extern "C" void _s8029DA7C_22();
extern "C" void _s8029DA7C_23();

struct AptAnimationPoolData {
    void HandleFocusButton_AptInputType();
};

void AptAnimationPoolData::HandleFocusButton_AptInputType() {
}
