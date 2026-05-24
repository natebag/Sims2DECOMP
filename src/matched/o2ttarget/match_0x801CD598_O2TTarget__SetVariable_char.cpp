// 0x801CD598 O2TTarget::SetVariable(char (2460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); mr 29,5; extsb 3,3; bl _s801CD598_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,14556; bl _s801CD598_1; cmpwi 3,0; bne 1f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_2; b 49f; 1:; lis 3,-32705; mr 4,31; addi 3,3,14728; bl _s801CD598_3; cmpwi 3,0; bne 2f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_4; b 49f; 2:; lis 3,-32705; mr 4,31; addi 3,3,14748; bl _s801CD598_5; cmpwi 3,0; bne 3f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_6; b 49f; 3:; lis 3,-32705; mr 4,31; addi 3,3,14772; bl _s801CD598_7; cmpwi 3,0; bne 4f; lwz 0,0x254(30); cmpwi 0,0; bne 49f; lwz 0,0x248(30); cmpwi 0,0; bne 49f; li 0,1; lis 3,-32705; addi 3,3,15436; stw 0,0x90(30); li 4,0; li 5,0; li 6,0; li 7,0; bl _s801CD598_8; lis 3,-32705; li 4,7; b 26f; 4:; lis 3,-32705; mr 4,31; addi 3,3,14608; bl _s801CD598_9; cmpwi 3,0; beq 7f; lis 3,-32705; mr 4,31; addi 3,3,14596; bl _s801CD598_10; cmpwi 3,0; bne 8f; mr 3,29; bl _s801CD598_11; lwz 0,0x88(30); cmpwi 3,1; stw 0,0x8c(30); bne 5f; stw 3,0x88(30); mr 3,30; bl _s801CD598_12; b 7f; 5:; cmpwi 3,2; bne 6f; stw 3,0x88(30); mr 3,30; bl _s801CD598_13; b 7f; 6:; cmpwi 3,0; bne 7f; stw 3,0x88(30); 7:; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_14; b 49f; 8:; lis 3,-32705; mr 4,31; addi 3,3,14788; bl _s801CD598_15; cmpwi 3,0; bne 9f; mr 3,30; bl _s801CD598_16; b 49f; 9:; lis 3,-32705; mr 4,31; addi 3,3,14624; bl _s801CD598_17; cmpwi 3,0; bne 10f; mr 3,30; bl _s801CD598_18; b 49f; 10:; lis 3,-32705; mr 4,31; addi 3,3,14672; bl _s801CD598_19; cmpwi 3,0; bne 11f; mr 3,29; bl _s801CD598_20; lis 9,-32705; lis 11,-32705; lfs f12,0x3c9c(9); lfs f13,0x3ca0(11); lwz 3,-21492(13); fmadds f1,f1,f12,f13; fctiwz f0,f1; stfd f0,0x40(1); lwz 4,0x44(1); bl _s801CD598_21; b 49f; 11:; lis 3,-32705; mr 4,31; addi 3,3,14688; bl _s801CD598_22; cmpwi 3,0; bne 12f; mr 3,29; bl _s801CD598_23; lis 9,-32705; lis 11,-32705; lfs f12,0x3c9c(9); lfs f13,0x3ca0(11); lwz 3,-21492(13); fmadds f1,f1,f12,f13; fctiwz f0,f1; stfd f0,0x40(1); lwz 4,0x44(1); bl _s801CD598_24; b 49f; 12:; lis 3,-32705; mr 4,31; addi 3,3,14580; bl _s801CD598_25; cmpwi 3,0; bne 27f; lis 3,-32697; li 4,0; addi 3,3,24012; li 29,0; bl _s801CD598_26; lis 31,-32697; cmpwi 3,0; bne 13f; addi 3,31,24012; li 4,1; bl _s801CD598_27; cmpwi 3,0; beq 15f; 13:; lis 5,-32705; addi 4,31,24012; addi 5,5,15456; addi 3,1,24; crxor 6,6,6; bl _s801CD598_28; li 29,1; lwz 9,0x18(1); addi 31,30,488; li 4,0; cmpwi 9,0; beq 14f; lwz 4,0x0(9); 14:; mr 3,31; bl _s801CD598_29; b 17f; 15:; lwz 11,-21496(13); cmpwi 11,0; beq 17f; lwz 9,0x0(11); li 4,24; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 17f; lis 5,-32705; addi 4,31,24012; addi 5,5,15480; addi 3,1,28; crxor 6,6,6; bl _s801CD598_30; li 29,1; lwz 9,0x1c(1); addi 31,30,488; li 4,0; cmpwi 9,0; beq 16f; lwz 4,0x0(9); 16:; mr 3,31; bl _s801CD598_31; 17:; cmpwi 29,0; beq 25f; lis 9,-32705; li 10,0; addi 9,9,15504; li 0,1; lwz 7,0x0(9); lwz 8,0x4(9); addi 11,30,448; stw 0,0x1c0(30); lis 9,-32708; stw 10,0x1e0(30); mr 29,11; stw 7,0x20(1); stw 8,0x24(1); addi 31,9,-28780; stw 10,0x1cc(30); addi 4,1,32; stw 10,0x1d4(30); cmpwi 11,0; stw 11,0x10(1); beq 18f; addi 3,1,8; li 5,8; bl _s801CD598_32; b 19f; 18:; stw 29,0x8(1); 19:; stw 31,0x14(1); lis 9,-32705; addi 11,1,8; lwz 5,0x8(1); addi 9,9,6448; lwz 4,0x4(11); lwz 6,0x8(11); addi 10,30,528; lwz 0,0xc(11); mr 31,11; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 29,0; stw 5,0x210(30); lis 9,-32709; stw 0,0xc(10); addi 28,9,4004; stw 4,0x4(10); addi 9,1,40; stw 6,0x8(10); stw 7,0x28(1); stw 8,0x2c(1); stw 29,0x10(1); beq 20f; mr 4,9; mr 3,31; li 5,8; bl _s801CD598_33; b 21f; 20:; stw 29,0x8(1); 21:; stw 28,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-1960; lwz 5,0x8(31); addi 11,30,544; lwz 10,0x4(31); addi 4,1,48; lwz 0,0xc(31); cmpwi 29,0; stw 6,0x220(30); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 28,9,4004; stw 5,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 29,0x10(1); beq 22f; mr 3,31; li 5,8; bl _s801CD598_34; b 23f; 22:; stw 29,0x8(1); 23:; stw 28,0x14(1); addi 9,30,560; lwz 11,0x8(1); lis 4,-32697; lwz 10,0xc(31); lis 5,-32705; lwz 8,0x4(31); addi 4,4,24012; lwz 0,0x8(31); addi 5,5,-1988; stw 11,0x230(30); addi 3,1,56; stw 10,0xc(9); addi 31,30,496; stw 8,0x4(9); stw 0,0x8(9); crxor 6,6,6; bl _s801CD598_35; lwz 9,0x38(1); li 4,0; cmpwi 9,0; beq 24f; lwz 4,0x0(9); 24:; mr 3,31; bl _s801CD598_36; li 0,0; mr 3,29; stw 0,0x1e4(30); bl _s801CD598_37; b 49f; 25:; lwz 0,0x248(30); cmpwi 0,0; bne 49f; lwz 0,0x254(30); cmpwi 0,0; bne 49f; li 0,1; lis 3,-32705; addi 3,3,15436; stw 0,0x90(30); li 4,0; li 5,0; li 6,0; li 7,0; bl _s801CD598_38; lis 3,-32705; li 4,4; 26:; addi 3,3,-2032; bl _s801CD598_39; lis 3,-32705; addi 3,3,-2020; bl _s801CD598_40; b 49f; 27:; lwz 3,-29752(13); mr 4,31; bl _s801CD598_41; cmpwi 3,0; bne 28f; li 0,1; mr 3,30; stw 0,0x258(30); mr 4,31; mr 5,29; bl _s801CD598_42; b 49f; 28:; lis 3,-32705; mr 4,31; addi 3,3,14252; bl _s801CD598_43; cmpwi 3,0; bne 29f; mr 3,29; bl _s801CD598_44; lis 9,-32705; lis 11,-32705; lfs f12,0x3c9c(9); lfs f13,0x3ca0(11); lwz 3,-21492(13); fmadds f1,f1,f12,f13; fctiwz f0,f1; stfd f0,0x40(1); lwz 4,0x44(1); bl _s801CD598_45; b 49f; 29:; lis 3,-32705; mr 4,31; addi 3,3,14280; bl _s801CD598_46; cmpwi 3,0; bne 30f; mr 3,29; bl _s801CD598_47; lis 9,-32705; lis 11,-32705; lfs f12,0x3c9c(9); lfs f13,0x3ca0(11); lwz 3,-21492(13); fmadds f1,f1,f12,f13; fctiwz f0,f1; stfd f0,0x40(1); lwz 4,0x44(1); bl _s801CD598_48; b 49f; 30:; lis 3,-32705; mr 4,31; addi 3,3,14312; bl _s801CD598_49; cmpwi 3,0; bne 31f; mr 3,29; bl _s801CD598_50; mr 3,30; bl _s801CD598_51; lis 9,-32697; addi 9,9,24012; lwz 11,0x148(9); stb 3,0x1f(11); b 32f; 31:; lis 3,-32705; mr 4,31; addi 3,3,14348; bl _s801CD598_52; cmpwi 3,0; bne 33f; mr 3,29; bl _s801CD598_53; mr 3,30; bl _s801CD598_54; lis 9,-32697; addi 9,9,24012; lwz 11,0x148(9); stb 3,0x20(11); 32:; mr 3,9; bl _s801CD598_55; b 49f; 33:; lis 3,-32705; mr 4,31; addi 3,3,14660; bl _s801CD598_56; cmpwi 3,0; bne 35f; mr 3,29; bl _s801CD598_57; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 34f; li 0,0; 34:; stw 0,0x4(9); beq 49f; lwz 4,0x1b4(30); lwz 3,-26524(13); bl _s801CD598_58; lwz 10,-21432(13); lis 9,-32705; lis 11,-32705; rlwinm 4,3,0,24,31; lfs f1,0x3c98(9); lfs f3,0x3ca4(11); lwz 3,0x110(10); fmr f2,f1; fmr f4,f3; bl _s801CD598_59; b 49f; 35:; lis 3,-32705; mr 4,31; addi 3,3,14384; bl _s801CD598_60; cmpwi 3,0; bne 37f; mr 3,29; bl _s801CD598_61; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 36f; li 0,0; 36:; stw 0,0x0(9); b 49f; 37:; lis 3,-32705; mr 4,31; addi 3,3,14640; bl _s801CD598_62; cmpwi 3,0; bne 39f; mr 3,29; bl _s801CD598_63; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 38f; li 0,0; 38:; stw 0,0x18(9); b 49f; 39:; lis 3,-32705; mr 4,31; addi 3,3,14708; bl _s801CD598_64; cmpwi 3,0; bne 41f; mr 3,29; bl _s801CD598_65; lis 9,-32697; cmpwi 3,0; lwz 9,0x5f14(9); li 0,1; bne 40f; li 0,0; 40:; stw 0,0x24(9); b 49f; 41:; lis 3,-32705; mr 4,31; addi 3,3,14460; bl _s801CD598_66; cmpwi 3,0; bne 42f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_67; b 49f; 42:; lis 3,-32705; mr 4,31; addi 3,3,14476; bl _s801CD598_68; cmpwi 3,0; bne 43f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_69; b 49f; 43:; lis 3,-32705; mr 4,31; addi 3,3,14492; bl _s801CD598_70; cmpwi 3,0; bne 44f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_71; b 49f; 44:; lis 28,-32705; mr 4,31; addi 3,28,14504; bl _s801CD598_72; cmpwi 3,0; beq 45f; addi 3,28,14504; mr 4,31; bl _s801CD598_73; cmpwi 3,0; bne 46f; 45:; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_74; b 49f; 46:; lis 3,-32705; mr 4,31; addi 3,3,14520; bl _s801CD598_75; cmpwi 3,0; bne 47f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_76; b 49f; 47:; lis 3,-32705; mr 4,31; addi 3,3,14536; bl _s801CD598_77; cmpwi 3,0; bne 48f; mr 3,30; mr 4,31; mr 5,29; bl _s801CD598_78; b 49f; 48:; lis 3,-32705; mr 4,31; addi 3,3,14440; bl _s801CD598_79; cmpwi 3,0; bne 49f; lis 9,-32697; lis 4,-32705; lwz 11,0x5ef8(9); lis 5,-32705; addi 4,4,-5352; addi 5,5,-5340; lwz 9,0x80(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 49:; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"

extern "C" void _s801CD598_0();
extern "C" void _s801CD598_1();
extern "C" void _s801CD598_2();
extern "C" void _s801CD598_3();
extern "C" void _s801CD598_4();
extern "C" void _s801CD598_5();
extern "C" void _s801CD598_6();
extern "C" void _s801CD598_7();
extern "C" void _s801CD598_8();
extern "C" void _s801CD598_9();
extern "C" void _s801CD598_10();
extern "C" void _s801CD598_11();
extern "C" void _s801CD598_12();
extern "C" void _s801CD598_13();
extern "C" void _s801CD598_14();
extern "C" void _s801CD598_15();
extern "C" void _s801CD598_16();
extern "C" void _s801CD598_17();
extern "C" void _s801CD598_18();
extern "C" void _s801CD598_19();
extern "C" void _s801CD598_20();
extern "C" void _s801CD598_21();
extern "C" void _s801CD598_22();
extern "C" void _s801CD598_23();
extern "C" void _s801CD598_24();
extern "C" void _s801CD598_25();
extern "C" void _s801CD598_26();
extern "C" void _s801CD598_27();
extern "C" void _s801CD598_28();
extern "C" void _s801CD598_29();
extern "C" void _s801CD598_30();
extern "C" void _s801CD598_31();
extern "C" void _s801CD598_32();
extern "C" void _s801CD598_33();
extern "C" void _s801CD598_34();
extern "C" void _s801CD598_35();
extern "C" void _s801CD598_36();
extern "C" void _s801CD598_37();
extern "C" void _s801CD598_38();
extern "C" void _s801CD598_39();
extern "C" void _s801CD598_40();
extern "C" void _s801CD598_41();
extern "C" void _s801CD598_42();
extern "C" void _s801CD598_43();
extern "C" void _s801CD598_44();
extern "C" void _s801CD598_45();
extern "C" void _s801CD598_46();
extern "C" void _s801CD598_47();
extern "C" void _s801CD598_48();
extern "C" void _s801CD598_49();
extern "C" void _s801CD598_50();
extern "C" void _s801CD598_51();
extern "C" void _s801CD598_52();
extern "C" void _s801CD598_53();
extern "C" void _s801CD598_54();
extern "C" void _s801CD598_55();
extern "C" void _s801CD598_56();
extern "C" void _s801CD598_57();
extern "C" void _s801CD598_58();
extern "C" void _s801CD598_59();
extern "C" void _s801CD598_60();
extern "C" void _s801CD598_61();
extern "C" void _s801CD598_62();
extern "C" void _s801CD598_63();
extern "C" void _s801CD598_64();
extern "C" void _s801CD598_65();
extern "C" void _s801CD598_66();
extern "C" void _s801CD598_67();
extern "C" void _s801CD598_68();
extern "C" void _s801CD598_69();
extern "C" void _s801CD598_70();
extern "C" void _s801CD598_71();
extern "C" void _s801CD598_72();
extern "C" void _s801CD598_73();
extern "C" void _s801CD598_74();
extern "C" void _s801CD598_75();
extern "C" void _s801CD598_76();
extern "C" void _s801CD598_77();
extern "C" void _s801CD598_78();
extern "C" void _s801CD598_79();

struct O2TTarget {
    void SetVariable();
};

void O2TTarget::SetVariable() {
}
