// 0x800EE2B4 ObjectFolderImpl::LoadDatabase(void) (1752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stfd f31,0x60(1); stmw 18,0x28(1); stw 0,0x6c(1); stw 12,0x24(1); mr 25,3; addi 29,1,8; lis 3,-32693; mr 18,29; addi 3,3,27900; bl _s800EE2B4_0; lis 9,-32706; lwz 11,-26532(13); lfs f0,-19240(9); lis 30,-32693; addi 30,30,-11760; stfs f0,0x8(1); mr 4,30; stfs f0,0x4(29); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(29); lwz 9,0x0(11); fsubs f31,f1,f0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; fmr f2,f1; lis 3,-32706; stfs f2,0x4(29); addi 3,3,-19796; fmr f1,f31; lfs f0,0x8(1); fsubs f2,f2,f0; creqv 6,6,6; bl _s800EE2B4_1; lwz 11,-26532(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(29); lwz 9,0x0(11); fsubs f31,f1,f0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; fmr f2,f1; lis 3,-32706; stfs f2,0x4(29); fmr f1,f31; addi 3,3,-19744; lfs f0,0x8(1); fsubs f2,f2,f0; creqv 6,6,6; bl _s800EE2B4_2; lis 28,-32692; lis 4,3123; addi 28,28,-20832; li 5,0; li 6,0; ori 4,4,56129; mr 3,28; bl _s800EE2B4_3; stw 3,0x690(25); mr 4,30; lwz 11,-26532(13); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(29); lwz 9,0x0(11); fsubs f31,f1,f0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; fmr f2,f1; lis 3,-32706; stfs f2,0x4(29); addi 3,3,-19660; fmr f1,f31; lfs f0,0x8(1); fsubs f2,f2,f0; creqv 6,6,6; bl _s800EE2B4_4; lwz 11,-26532(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(29); lwz 9,0x0(11); fsubs f31,f1,f0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; fmr f2,f1; lis 3,-32706; stfs f2,0x4(29); fmr f1,f31; addi 3,3,-19576; lfs f0,0x8(1); fsubs f2,f2,f0; creqv 6,6,6; bl _s800EE2B4_5; lis 4,10794; li 6,0; li 5,0; mr 3,28; ori 4,4,62569; bl _s800EE2B4_6; stw 3,0x694(25); mr 4,30; lwz 11,-26532(13); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(29); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; fmr f2,f1; lis 3,-32706; stfs f2,0x4(29); fmr f1,f31; addi 3,3,-19500; lfs f0,0x8(1); fsubs f2,f2,f0; creqv 6,6,6; bl _s800EE2B4_7; lis 4,-32706; lwz 3,0x690(25); addi 4,4,-19424; bl _s800EE2B4_8; mr 22,3; lis 4,-32706; lwz 3,0x690(25); addi 4,4,-19416; bl _s800EE2B4_9; mr 30,3; lis 4,-32706; lwz 3,0x694(25); addi 4,4,-19400; bl _s800EE2B4_10; mr 19,3; lis 5,-32706; lwz 3,0x690(25); mr 4,30; addi 5,5,-19388; bl _s800EE2B4_11; mr 28,3; lwz 5,-31852(13); lwz 3,0x690(25); mr 4,30; bl _s800EE2B4_12; lwz 29,0x3c(25); lwz 31,0x0(28); lwz 20,0x0(3); lwz 21,0xc(22); mr 3,29; mr 4,31; bl _s800EE2B4_13; mr. 30,3; bne 1f; li 3,16; bl _s800EE2B4_14; bl _s800EE2B4_15; mr 30,3; li 4,0; stw 31,0x8(30); li 5,0; bl _s800EE2B4_16; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; cmpwi 30,0; beq 0f; lwz 9,0xc(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; 0:; li 3,0; b 2f; 1:; mr 3,29; mr 4,30; bl _s800EE2B4_17; mr 3,30; 2:; stw 3,0x440(25); addi 5,1,16; lwz 3,0x690(25); lwz 4,0x0(28); bl _s800EE2B4_18; cmpwi 3,0; li 0,-1; beq 3f; lwz 0,0x10(1); 3:; cmpwi 0,0; bne 4f; li 0,-1; 4:; lwz 3,0x690(25); mr 4,20; stw 0,-31848(13); addi 5,1,20; bl _s800EE2B4_19; cmpwi 3,0; li 0,-1; beq 5f; lwz 0,0x14(1); 5:; mr. 0,0; bne 6f; li 0,-1; 6:; stw 0,0x698(25); lis 30,-32693; lwz 11,-26532(13); addi 30,30,-11760; mr 4,30; li 28,0; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(18); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lfs f2,0x8(1); fmr f0,f1; lis 3,-32706; fmr f1,f31; fsubs f2,f0,f2; addi 3,3,-19380; stfs f0,0x4(18); creqv 6,6,6; bl _s800EE2B4_20; cmplw 28,21; bge 19f; 7:; mulli 11,28,72; lwz 9,0x4(22); li 27,0; lwzx 10,9,11; add 31,9,11; cmpwi 10,0; beq 8f; lwz 27,-4(10); 8:; lwz 6,0x8(22); cmpwi 6,0; beq 9f; rlwinm 9,28,2,0,29; lwzx 26,9,6; b 10f; 9:; lis 9,-32706; addi 26,9,-19312; 10:; lwz 29,0x3c(25); mr 4,31; li 23,0; mr 3,29; bl _s800EE2B4_21; mr. 30,3; bne 11f; li 3,16; bl _s800EE2B4_22; bl _s800EE2B4_23; mr 30,3; li 4,0; stw 31,0x8(30); li 5,0; bl _s800EE2B4_24; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 11f; cmpwi 30,0; beq 12f; lwz 9,0xc(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; b 12f; 11:; mr 3,29; mr 4,30; bl _s800EE2B4_25; 12:; lwz 5,0x38(31); cmpwi 5,0; beq 13f; lwz 3,0x694(25); mr 4,19; bl _s800EE2B4_26; mr 23,3; 13:; addi 24,28,1; cmpwi 27,0; cmpw cr4,20,31; ble 17f; mr 28,27; li 27,0; 14:; lwz 9,0x0(31); addi 5,1,24; lwz 3,0x690(25); li 30,0; lwzx 29,9,27; mr 4,29; bl _s800EE2B4_27; mr. 3,3; beq 15f; lwz 3,0x8(3); cmpwi 3,0; beq 15f; lwz 9,0x18(1); rlwinm 9,9,2,0,29; lwzx 30,9,3; 15:; cmpwi 30,0; bne 16f; mr 30,26; 16:; lwz 9,0x0(25); mr 4,29; mr 5,30; mr 6,26; lha 3,0x208(9); mr 7,31; lwz 0,0x20c(9); addi 27,27,4; mr 9,23; add 3,25,3; lha 8,0xbc(4); mtspr 8,0; blrl; addic. 28,28,-1; bne 14b; 17:; bne cr4,18f; lwz 9,0x0(31); addi 3,25,1692; lwz 4,0x0(9); bl _s800EE2B4_28; 18:; mr 28,24; cmplw 28,21; blt 7b; 19:; lwz 11,-26532(13); lis 30,-32693; addi 30,30,-11760; lwz 9,0x0(11); mr 4,30; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(18); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lfs f0,0x8(1); fmr f2,f1; stfs f2,0x4(18); lis 3,-32706; fsubs f2,f2,f0; addi 3,3,-19308; fmr f1,f31; creqv 6,6,6; bl _s800EE2B4_29; lis 3,-32693; addi 3,3,27900; bl _s800EE2B4_30; lwz 0,0x6c(1); lwz 12,0x24(1); mtspr 8,0; lmw 18,0x28(1); lfd f31,0x60(1); mtcrf 8,12; addi 1,1,104"

extern "C" void _s800EE2B4_0();
extern "C" void _s800EE2B4_1();
extern "C" void _s800EE2B4_2();
extern "C" void _s800EE2B4_3();
extern "C" void _s800EE2B4_4();
extern "C" void _s800EE2B4_5();
extern "C" void _s800EE2B4_6();
extern "C" void _s800EE2B4_7();
extern "C" void _s800EE2B4_8();
extern "C" void _s800EE2B4_9();
extern "C" void _s800EE2B4_10();
extern "C" void _s800EE2B4_11();
extern "C" void _s800EE2B4_12();
extern "C" void _s800EE2B4_13();
extern "C" void _s800EE2B4_14();
extern "C" void _s800EE2B4_15();
extern "C" void _s800EE2B4_16();
extern "C" void _s800EE2B4_17();
extern "C" void _s800EE2B4_18();
extern "C" void _s800EE2B4_19();
extern "C" void _s800EE2B4_20();
extern "C" void _s800EE2B4_21();
extern "C" void _s800EE2B4_22();
extern "C" void _s800EE2B4_23();
extern "C" void _s800EE2B4_24();
extern "C" void _s800EE2B4_25();
extern "C" void _s800EE2B4_26();
extern "C" void _s800EE2B4_27();
extern "C" void _s800EE2B4_28();
extern "C" void _s800EE2B4_29();
extern "C" void _s800EE2B4_30();

struct ObjectFolderImpl {
    void LoadDatabase();
};

void ObjectFolderImpl::LoadDatabase() {
}
