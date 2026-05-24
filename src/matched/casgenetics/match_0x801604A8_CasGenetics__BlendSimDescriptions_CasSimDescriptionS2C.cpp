// 0x801604A8 CasGenetics::BlendSimDescriptions(CasSimDescriptionS2C (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,6; mr 29,3; mr 28,4; mr 27,5; mr 30,7; li 4,0; mr 3,31; bl _s801604A8_0; stw 30,0x84(31); mr 3,29; lbz 4,0x89(28); lbz 5,0x89(27); extsb 4,4; extsb 5,5; bl _s801604A8_1; extsb 0,3; stb 3,0x89(31); cmpwi 0,5; bne 0f; li 0,1; stb 0,0x8c(31); 0:; mr 3,29; li 4,2; mr 5,31; li 6,0; bl _s801604A8_2; li 30,3; mr 3,29; li 4,7; mr 5,31; li 6,0; bl _s801604A8_3; mr 3,29; li 4,15; mr 5,31; li 6,0; bl _s801604A8_4; mr 3,29; li 4,16; mr 5,31; li 6,0; bl _s801604A8_5; mr 3,29; li 4,19; mr 5,31; li 6,25; bl _s801604A8_6; mr 3,29; li 4,0; mr 5,31; li 6,25; bl _s801604A8_7; mr 3,29; li 4,18; mr 5,31; li 6,50; bl _s801604A8_8; mr 3,29; li 4,20; mr 5,31; li 6,25; bl _s801604A8_9; li 4,21; mr 5,31; li 6,10; mr 3,29; bl _s801604A8_10; bl _s801604A8_11; mr 4,3; li 6,25; divwu 30,4,30; mr 5,31; mr 3,29; mulli 30,30,3; subf 4,30,4; addi 4,4,22; bl _s801604A8_12; lbz 4,0x88(28); mr 3,29; lbz 5,0x88(27); extsb 4,4; extsb 5,5; bl _s801604A8_13; stb 3,0x88(31); mr 3,31; bl _s801604A8_14; lfs f2,0x104(27); mr 3,29; lfs f1,0x104(28); bl _s801604A8_15; stfs f1,0x104(31); mr 3,29; lfs f1,0x108(28); lfs f2,0x108(27); bl _s801604A8_16; stfs f1,0x108(31); mr 3,29; lfs f1,0x10c(28); lfs f2,0x10c(27); bl _s801604A8_17; stfs f1,0x10c(31); mr 3,29; lfs f1,0x110(28); lfs f2,0x110(27); bl _s801604A8_18; stfs f1,0x110(31); mr 3,29; lfs f1,0x114(28); lfs f2,0x114(27); bl _s801604A8_19; stfs f1,0x114(31); mr 3,29; mr 4,31; bl _s801604A8_20; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801604A8_0();
extern "C" void _s801604A8_1();
extern "C" void _s801604A8_2();
extern "C" void _s801604A8_3();
extern "C" void _s801604A8_4();
extern "C" void _s801604A8_5();
extern "C" void _s801604A8_6();
extern "C" void _s801604A8_7();
extern "C" void _s801604A8_8();
extern "C" void _s801604A8_9();
extern "C" void _s801604A8_10();
extern "C" void _s801604A8_11();
extern "C" void _s801604A8_12();
extern "C" void _s801604A8_13();
extern "C" void _s801604A8_14();
extern "C" void _s801604A8_15();
extern "C" void _s801604A8_16();
extern "C" void _s801604A8_17();
extern "C" void _s801604A8_18();
extern "C" void _s801604A8_19();
extern "C" void _s801604A8_20();

struct CasGenetics {
    void BlendSimDescriptions_CasSimDescriptionS2C();
};

void CasGenetics::BlendSimDescriptions_CasSimDescriptionS2C() {
}
