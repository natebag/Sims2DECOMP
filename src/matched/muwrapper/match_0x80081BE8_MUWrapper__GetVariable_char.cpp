// 0x80081BE8 MUWrapper::GetVariable(char (2328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 27,0x24(1); stw 0,0x44(1); mr 29,3; addi 30,1,8; mr 31,4; li 3,64; bl _s80081BE8_0; mr 27,30; mr 28,3; mr 4,31; li 5,64; bl _s80081BE8_1; lis 9,-32707; li 0,0; lfs f31,0x7098(9); lis 3,-32707; stb 0,0x3f(28); addi 3,3,28364; stfs f31,0x8(1); mr 4,31; stfs f31,0x4(30); bl _s80081BE8_2; cmpwi 3,0; beq 0f; lis 3,-32707; mr 4,31; addi 3,3,28384; bl _s80081BE8_3; cmpwi 3,0; bne 3f; 0:; lwz 3,0xac(29); li 5,0; cmpwi 3,7; beq 1f; cmpwi 3,14; bne 2f; 1:; li 5,2; 2:; lis 4,-32707; mr 3,28; addi 4,4,27968; crxor 6,6,6; bl _s80081BE8_4; b 61f; 3:; lis 3,-32707; mr 4,31; addi 3,3,28412; bl _s80081BE8_5; cmpwi 3,0; bne 5f; lwz 9,0xa8(29); lwz 10,0x60(9); lwz 11,0x1c(10); lwz 0,0x74(11); lha 3,0x70(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0xb0(29); lwz 0,0x4(3); lwz 11,0x0(3); addi 9,9,-12; stw 0,0x4(27); cmplwi 9,1; stw 11,0x8(1); bgt 4f; stfs f31,0x8(1); 4:; lfs f0,0xec(29); lis 4,-32707; lfs f1,0x8(1); addi 4,4,28440; mr 3,28; fdivs f1,f1,f0; b 58f; 5:; lis 3,-32707; mr 4,31; addi 3,3,28444; bl _s80081BE8_6; cmpwi 3,0; beq 6f; lis 3,-32707; mr 4,31; addi 3,3,28460; bl _s80081BE8_7; cmpwi 3,0; bne 7f; 6:; lfs f1,0xec(29); lis 4,-32707; addi 4,4,28440; mr 3,28; b 58f; 7:; lis 3,-32707; mr 4,31; addi 3,3,28480; bl _s80081BE8_8; cmpwi 3,0; beq 8f; lis 3,-32707; mr 4,31; addi 3,3,28500; bl _s80081BE8_9; cmpwi 3,0; bne 9f; 8:; lfs f1,0xf0(29); lis 4,-32707; addi 4,4,28440; mr 3,28; b 58f; 9:; lis 3,-32707; mr 4,31; addi 3,3,28524; bl _s80081BE8_10; cmpwi 3,0; bne 10f; lis 9,-32707; lfs f0,0xec(29); lfs f13,0x709c(9); lis 4,-32707; lfs f1,0xe4(29); addi 4,4,28440; fmuls f0,f0,f13; mr 3,28; fsubs f1,f1,f0; b 58f; 10:; lis 3,-32707; mr 4,31; addi 3,3,28536; bl _s80081BE8_11; cmpwi 3,0; bne 11f; lis 9,-32707; lfs f0,0xf0(29); lfs f12,0x709c(9); lis 11,-32707; lfs f1,0xe8(29); lis 4,-32707; fmuls f0,f0,f12; lfs f13,0x70a0(11); fsubs f1,f1,f0; addi 4,4,28440; fsubs f1,f1,f13; mr 3,28; b 58f; 11:; lis 3,-32707; mr 4,31; addi 3,3,28548; bl _s80081BE8_12; cmpwi 3,0; bne 12f; lis 4,-32707; mr 3,28; addi 4,4,27968; li 5,1; crxor 6,6,6; bl _s80081BE8_13; b 61f; 12:; lis 3,-32707; mr 4,31; addi 3,3,28188; bl _s80081BE8_14; cmpwi 3,0; bne 13f; lis 4,-32707; mr 3,28; addi 4,4,27968; li 5,0; crxor 6,6,6; bl _s80081BE8_15; b 61f; 13:; lis 3,-32707; mr 4,31; addi 3,3,28564; bl _s80081BE8_16; cmpwi 3,0; bne 14f; lwz 3,0xa8(29); bl _s80081BE8_17; xoris 3,3,32768; stw 3,0x1c(1); lis 7,17200; lwz 10,-26392(13); mr 11,9; stw 7,0x18(1); lis 8,-32707; lwz 0,0x18(10); lis 4,-32707; lfd f13,0x18(1); addi 4,4,28440; xoris 0,0,32768; lfd f12,0x70a8(8); stw 0,0x1c(1); mr 3,28; fsub f13,f13,f12; stw 7,0x18(1); frsp f13,f13; lfd f0,0x18(1); fsub f0,f0,f12; frsp f0,f0; fdivs f13,f13,f0; fmr f1,f13; creqv 6,6,6; bl _s80081BE8_18; b 61f; 14:; lis 3,-32707; mr 4,31; addi 3,3,28580; bl _s80081BE8_19; cmpwi 3,0; bne 21f; lwz 0,0xac(29); cmpwi 0,7; beq 15f; cmpwi 0,14; bne 16f; 15:; lwz 3,0xa8(29); li 4,2; li 5,0; b 20f; 16:; cmpwi 0,1; beq 17f; cmpwi 0,10; beq 17f; cmpwi 0,11; bne 18f; 17:; lwz 3,0xa8(29); li 4,2; li 5,3; b 20f; 18:; cmpwi 0,6; beq 19f; cmpwi 0,9; bne 42f; 19:; lwz 3,0xa8(29); li 4,2; li 5,5; 20:; bl _s80081BE8_20; lwz 9,0x1c(3); lha 0,0xd8(9); lwz 9,0xdc(9); b 41f; 21:; lis 3,-32707; mr 4,31; addi 3,3,28600; bl _s80081BE8_21; cmpwi 3,0; bne 27f; lwz 0,0xac(29); lis 9,-32707; lfs f31,0x70b0(9); cmpwi 0,7; beq 22f; cmpwi 0,14; bne 23f; 22:; lwz 3,0xa8(29); li 4,2; li 5,0; b 40f; 23:; cmpwi 0,1; beq 24f; cmpwi 0,10; beq 24f; cmpwi 0,11; bne 25f; 24:; lwz 3,0xa8(29); li 4,2; li 5,3; b 40f; 25:; cmpwi 0,6; beq 26f; cmpwi 0,9; bne 42f; 26:; lwz 3,0xa8(29); li 4,2; li 5,5; b 40f; 27:; lis 3,-32707; mr 4,31; addi 3,3,28620; bl _s80081BE8_22; cmpwi 3,0; bne 32f; lwz 9,0xac(29); cmpwi 9,7; beq 28f; cmpwi 9,14; bne 29f; 28:; lwz 3,0xa8(29); li 4,2; li 5,2; b 31f; 29:; addi 0,9,-1; cmplwi 0,1; ble 30f; cmpwi 9,10; beq 30f; cmpwi 9,11; bne 42f; 30:; lwz 3,0xa8(29); li 4,2; li 5,4; 31:; bl _s80081BE8_23; lwz 9,0x1c(3); lha 0,0xd8(9); lwz 9,0xdc(9); b 41f; 32:; lis 3,-32707; mr 4,31; addi 3,3,28640; bl _s80081BE8_24; cmpwi 3,0; bne 36f; lwz 11,0xac(29); lis 9,-32707; lfs f31,0x70b0(9); cmpwi 11,7; beq 33f; cmpwi 11,14; bne 34f; 33:; lwz 3,0xa8(29); li 4,2; li 5,2; b 40f; 34:; addi 0,11,-1; cmplwi 0,1; ble 35f; cmpwi 11,10; beq 35f; cmpwi 11,11; bne 42f; 35:; lwz 3,0xa8(29); li 4,2; li 5,4; b 40f; 36:; lis 3,-32707; mr 4,31; addi 3,3,28660; bl _s80081BE8_25; cmpwi 3,0; bne 37f; lwz 3,0xa8(29); li 4,2; li 5,1; bl _s80081BE8_26; lwz 0,0x4(3); andi. 9,0,1; beq 42f; lwz 3,0xa8(29); li 4,2; li 5,1; bl _s80081BE8_27; lwz 9,0x1c(3); lha 0,0xd8(9); lwz 9,0xdc(9); b 41f; 37:; lis 3,-32707; mr 4,31; addi 3,3,28680; bl _s80081BE8_28; cmpwi 3,0; bne 38f; lis 9,-32707; lwz 3,0xa8(29); lfs f31,0x70b0(9); li 4,2; li 5,1; bl _s80081BE8_29; lwz 0,0x4(3); andi. 9,0,1; beq 42f; lwz 3,0xa8(29); li 4,2; li 5,1; b 40f; 38:; lis 3,-32707; mr 4,31; addi 3,3,28700; bl _s80081BE8_30; cmpwi 3,0; bne 39f; lwz 3,0xa8(29); li 4,2; li 5,6; bl _s80081BE8_31; lwz 0,0x4(3); andi. 9,0,1; beq 42f; lwz 3,0xa8(29); li 4,2; li 5,6; bl _s80081BE8_32; lwz 9,0x1c(3); lha 0,0xd8(9); lwz 9,0xdc(9); b 41f; 39:; lis 3,-32707; mr 4,31; addi 3,3,28716; bl _s80081BE8_33; cmpwi 3,0; bne 43f; lis 9,-32707; lwz 3,0xa8(29); lfs f31,0x70b0(9); li 4,2; li 5,6; bl _s80081BE8_34; lwz 0,0x4(3); andi. 9,0,1; beq 42f; lwz 3,0xa8(29); li 4,2; li 5,6; 40:; bl _s80081BE8_35; lwz 9,0x1c(3); lha 0,0xe0(9); lwz 9,0xe4(9); 41:; add 3,3,0; mtspr 8,9; blrl; fmr f31,f1; 42:; lis 4,-32707; fmr f1,f31; addi 4,4,28440; mr 3,28; creqv 6,6,6; bl _s80081BE8_36; b 61f; 43:; lis 3,-32707; mr 4,31; addi 3,3,28732; bl _s80081BE8_37; cmpwi 3,0; bne 51f; lwz 0,0xac(29); cmpwi 0,7; beq 44f; cmpwi 0,14; bne 45f; 44:; lwz 3,0xa8(29); li 4,2; li 5,0; b 49f; 45:; cmpwi 0,1; beq 46f; cmpwi 0,10; beq 46f; cmpwi 0,11; bne 47f; 46:; lwz 3,0xa8(29); li 4,2; li 5,3; b 49f; 47:; cmpwi 0,6; beq 48f; cmpwi 0,9; bne 50f; 48:; lwz 3,0xa8(29); li 4,2; li 5,5; 49:; bl _s80081BE8_38; lwz 9,0x1c(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x4(3); lwz 9,0x0(3); stw 0,0x4(27); stw 9,0x8(1); 50:; lfs f1,0x8(1); lis 4,-32707; addi 4,4,28440; mr 3,28; b 58f; 51:; lis 3,-32707; mr 4,31; addi 3,3,28756; bl _s80081BE8_39; cmpwi 3,0; bne 57f; lwz 9,0xac(29); cmpwi 9,7; beq 52f; cmpwi 9,14; bne 53f; 52:; lwz 3,0xa8(29); li 4,2; li 5,2; b 55f; 53:; addi 0,9,-1; cmplwi 0,1; ble 54f; cmpwi 9,10; beq 54f; cmpwi 9,11; bne 56f; 54:; lwz 3,0xa8(29); li 4,2; li 5,4; 55:; bl _s80081BE8_40; lwz 9,0x1c(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x4(3); lwz 9,0x0(3); stw 0,0x4(27); stw 9,0x8(1); 56:; lfs f1,0x8(1); lis 4,-32707; addi 4,4,28440; mr 3,28; b 58f; 57:; lis 3,-32707; mr 4,31; addi 3,3,28780; bl _s80081BE8_41; cmpwi 3,0; bne 59f; lwz 3,0xa8(29); li 4,2; li 5,1; bl _s80081BE8_42; lwz 9,0x1c(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; lwz 9,0x0(3); lis 4,-32707; lwz 0,0x4(3); addi 4,4,28440; stw 9,0x8(1); mr 3,28; stw 0,0x4(27); lfs f1,0x8(1); 58:; creqv 6,6,6; bl _s80081BE8_43; b 61f; 59:; lis 3,-32707; mr 4,31; addi 3,3,28804; bl _s80081BE8_44; cmpwi 3,0; beq 60f; mr 3,28; bl _s80081BE8_45; li 3,0; b 62f; 60:; lwz 3,0xa8(29); li 4,2; li 5,6; bl _s80081BE8_46; lwz 9,0x1c(3); lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; lwz 9,0x0(3); lis 4,-32707; lwz 0,0x4(3); addi 4,4,28440; stw 9,0x8(1); mr 3,28; stw 0,0x4(27); lfs f1,0x8(1); creqv 6,6,6; bl _s80081BE8_47; 61:; mr 3,28; 62:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x24(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s80081BE8_0();
extern "C" void _s80081BE8_1();
extern "C" void _s80081BE8_2();
extern "C" void _s80081BE8_3();
extern "C" void _s80081BE8_4();
extern "C" void _s80081BE8_5();
extern "C" void _s80081BE8_6();
extern "C" void _s80081BE8_7();
extern "C" void _s80081BE8_8();
extern "C" void _s80081BE8_9();
extern "C" void _s80081BE8_10();
extern "C" void _s80081BE8_11();
extern "C" void _s80081BE8_12();
extern "C" void _s80081BE8_13();
extern "C" void _s80081BE8_14();
extern "C" void _s80081BE8_15();
extern "C" void _s80081BE8_16();
extern "C" void _s80081BE8_17();
extern "C" void _s80081BE8_18();
extern "C" void _s80081BE8_19();
extern "C" void _s80081BE8_20();
extern "C" void _s80081BE8_21();
extern "C" void _s80081BE8_22();
extern "C" void _s80081BE8_23();
extern "C" void _s80081BE8_24();
extern "C" void _s80081BE8_25();
extern "C" void _s80081BE8_26();
extern "C" void _s80081BE8_27();
extern "C" void _s80081BE8_28();
extern "C" void _s80081BE8_29();
extern "C" void _s80081BE8_30();
extern "C" void _s80081BE8_31();
extern "C" void _s80081BE8_32();
extern "C" void _s80081BE8_33();
extern "C" void _s80081BE8_34();
extern "C" void _s80081BE8_35();
extern "C" void _s80081BE8_36();
extern "C" void _s80081BE8_37();
extern "C" void _s80081BE8_38();
extern "C" void _s80081BE8_39();
extern "C" void _s80081BE8_40();
extern "C" void _s80081BE8_41();
extern "C" void _s80081BE8_42();
extern "C" void _s80081BE8_43();
extern "C" void _s80081BE8_44();
extern "C" void _s80081BE8_45();
extern "C" void _s80081BE8_46();
extern "C" void _s80081BE8_47();

struct MUWrapper {
    void GetVariable();
};

void MUWrapper::GetVariable() {
}
