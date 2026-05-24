// 0x800D7C20 NghResFile::CopyDefaultNghToCache(char (1808 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-400(1); mfspr 0,8; stfd f31,0x188(1); stmw 16,0x148(1); stw 0,0x194(1); lis 9,-32706; addi 27,1,8; lfs f0,-21196(9); mr 25,3; lwz 11,-26532(13); lis 28,-32693; stfs f0,0x8(1); mr 29,4; stfs f0,0x4(27); addi 28,28,-11760; mr 4,28; addi 30,1,16; lwz 9,0x0(11); addi 26,1,304; li 18,1; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; addi 4,1,24; stfs f1,0x4(27); addi 3,1,16; li 5,260; bl _s800D7C20_0; mr 5,30; mr 4,29; mr 3,25; bl _s800D7C20_1; mr 3,30; bl _s800D7C20_2; mr 5,3; lis 6,-32706; lis 3,-32694; li 9,0; addi 6,6,-21732; lis 7,-32768; lis 8,-32768; mr 4,26; addi 3,3,-10620; bl _s800D7C20_3; lwz 11,0x130(1); li 4,0; li 5,2; lwz 9,0x28(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x130(1); lwz 9,0x28(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x130(1); mr 30,3; li 4,0; li 5,0; lwz 9,0x28(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; mr 24,30; lis 9,-32696; addi 29,1,288; addi 9,9,25388; li 23,0; lwz 30,0x14(9); mr 20,9; bl _s800D7C20_4; mr 16,26; li 5,64; li 6,0; li 7,0; mr 4,30; bl _s800D7C20_5; mr 17,29; stw 20,0x120(1); mr 31,3; stw 23,0x4(29); mr 4,28; stw 23,0x8(29); mr 21,27; stw 23,0xc(29); lis 19,-32696; lwz 11,-26532(13); li 22,0; li 26,0; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,28; lfs f0,0x4(27); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; fmr f2,f1; lis 3,-32706; stfs f2,0x4(27); addi 3,3,-21628; fmr f1,f31; li 4,0; lfs f0,0x8(1); fsubs f2,f2,f0; creqv 6,6,6; bl _s800D7C20_6; cmpwi 24,0; ble 11f; lwz 9,0x124(1); lwz 11,0x120(1); mulli 9,9,24; lwz 0,0x4(11); add 9,9,0; lwz 29,0x4(9); cmpwi 29,0; beq 11f; li 27,0; 0:; lwz 3,-22652(13); mr 5,31; lwz 4,0x130(1); mr 6,22; lwz 11,0x0(3); mr 7,29; li 8,1; li 9,0; lha 0,0x70(11); lwz 11,0x74(11); add 3,3,0; mtspr 8,11; blrl; cmpw 29,3; bne 2f; cmpwi 23,1; mfcr 28; ble 1f; lwz 9,0x120(1); lwz 11,0x14(31); lwz 0,0x0(9); cmpw 11,0; beq 1f; cmpwi 11,7; bne 1f; lis 9,-32696; addi 20,9,25412; stw 20,0x120(1); 1:; addi 30,1,312; mr 3,25; bl _s800D7C20_7; li 0,1; mr 4,22; stw 0,0x14(3); addi 5,1,320; stw 27,0x138(1); mr 3,20; stw 27,0x4(30); addi 6,1,324; bl _s800D7C20_8; cmpwi 3,0; bne 3f; mr 3,25; bl _s800D7C20_9; addi 4,19,25388; mr 5,31; mr 6,26; mr 7,29; bl _s800D7C20_10; cmpwi 3,0; beq 4f; 2:; li 18,0; b 11f; 3:; stw 31,0x4(30); mr 6,30; stw 29,0x138(1); mr 3,25; lwz 4,0x140(1); lwz 5,0x144(1); bl _s800D7C20_11; 4:; mtcrf 128,28; ble 8f; lwz 0,0x14(31); cmpwi 0,8; beq 8f; cmplwi 0,7; bgt 8f; lwz 0,0x0(31); cmpwi 0,2; bne 8f; cmpwi 23,7; bne 8f; li 30,4; b 6f; 5:; addi 30,30,1; 6:; cmpwi 30,35; bgt 7f; mr 3,25; add 26,26,29; bl _s800D7C20_12; addi 4,19,25388; mr 5,31; mr 6,26; mr 7,29; bl _s800D7C20_13; cmpwi 3,0; beq 5b; li 18,0; 7:; cmpwi 18,0; beq 11f; 8:; lwz 6,0x124(1); subf 24,29,24; lwz 8,0x120(1); addi 23,23,1; mulli 10,6,24; lwz 11,0x12c(1); lwz 9,0x4(8); add 22,22,29; lwz 7,0x128(1); add 26,26,29; add 9,10,9; lwz 0,0x4(9); add 11,11,0; stw 11,0x12c(1); lwz 9,0x4(8); lwzx 9,9,10; addi 0,9,-1; cmpw 7,0; bge 9f; addi 0,7,1; stw 0,0x128(1); b 10f; 9:; cmpwi 9,0; ble 10f; addi 0,6,1; stw 27,0x8(17); stw 0,0x124(1); 10:; cmpwi 24,0; ble 11f; lwz 9,0x124(1); lwz 11,0x120(1); mulli 9,9,24; lwz 0,0x4(11); add 9,9,0; lwz 29,0x4(9); cmpwi 29,0; bne 0b; 11:; lwz 10,-26532(13); lis 9,-32693; addi 30,9,-11760; lwz 11,0x0(10); mr 4,30; lwz 0,0x2c(11); lha 3,0x28(11); mtspr 8,0; add 3,10,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(21); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lfs f2,0x8(1); fmr f0,f1; lis 3,-32706; fmr f1,f31; fsubs f2,f0,f2; mr 4,23; stfs f0,0x4(21); addi 3,3,-21568; creqv 6,6,6; bl _s800D7C20_14; bl _s800D7C20_15; mr 4,31; bl _s800D7C20_16; cmpwi 18,1; bne 14f; lwz 11,-26532(13); mr 4,30; addi 31,25,40; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(21); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lfs f2,0x8(1); fmr f0,f1; lis 3,-32706; fmr f1,f31; fsubs f2,f0,f2; addi 3,3,-21508; stfs f0,0x4(21); mr 4,23; creqv 6,6,6; bl _s800D7C20_17; li 30,0; 12:; addi 30,30,1; mr 3,25; mr 4,30; li 5,0; li 6,0; bl _s800D7C20_18; cmpwi 30,15; ble 12b; lwz 11,-26532(13); lis 30,-32693; addi 30,30,-11760; lwz 9,0x0(11); mr 4,30; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(21); lwz 9,0x0(11); fsubs f31,f1,f0; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lfs f2,0x8(1); fmr f0,f1; lis 3,-32706; fmr f1,f31; fsubs f2,f0,f2; stfs f0,0x4(21); addi 3,3,-21428; mr 4,23; creqv 6,6,6; bl _s800D7C20_19; lwz 4,-31932(13); mr 3,31; bl _s800D7C20_20; li 0,0; li 9,0; stb 0,0x134(25); mr 4,30; stw 9,0x20(25); lwz 11,-26532(13); lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(21); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lfs f2,0x8(1); fmr f0,f1; lis 3,-32706; fmr f1,f31; fsubs f2,f0,f2; addi 3,3,-21352; stfs f0,0x4(21); mr 4,23; creqv 6,6,6; bl _s800D7C20_21; li 30,0; 13:; addi 30,30,1; li 5,0; mr 4,30; mr 3,25; bl _s800D7C20_22; mr 3,25; mr 4,30; bl _s800D7C20_23; cmpwi 30,15; ble 13b; lwz 11,-26532(13); lis 30,-32693; addi 30,30,-11760; lwz 9,0x0(11); mr 4,30; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); mr 4,30; lfs f0,0x4(21); lwz 9,0x0(11); fsubs f31,f1,f0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; fmr f2,f1; lfs f0,0x8(1); stfs f2,0x4(21); lis 3,-32706; fsubs f2,f2,f0; addi 3,3,-21272; mr 4,23; fmr f1,f31; creqv 6,6,6; bl _s800D7C20_24; 14:; lis 3,-32694; mr 4,16; addi 3,3,-10620; bl _s800D7C20_25; mr 3,18; lwz 0,0x194(1); mtspr 8,0; lmw 16,0x148(1); lfd f31,0x188(1); addi 1,1,400"

extern "C" void _s800D7C20_0();
extern "C" void _s800D7C20_1();
extern "C" void _s800D7C20_2();
extern "C" void _s800D7C20_3();
extern "C" void _s800D7C20_4();
extern "C" void _s800D7C20_5();
extern "C" void _s800D7C20_6();
extern "C" void _s800D7C20_7();
extern "C" void _s800D7C20_8();
extern "C" void _s800D7C20_9();
extern "C" void _s800D7C20_10();
extern "C" void _s800D7C20_11();
extern "C" void _s800D7C20_12();
extern "C" void _s800D7C20_13();
extern "C" void _s800D7C20_14();
extern "C" void _s800D7C20_15();
extern "C" void _s800D7C20_16();
extern "C" void _s800D7C20_17();
extern "C" void _s800D7C20_18();
extern "C" void _s800D7C20_19();
extern "C" void _s800D7C20_20();
extern "C" void _s800D7C20_21();
extern "C" void _s800D7C20_22();
extern "C" void _s800D7C20_23();
extern "C" void _s800D7C20_24();
extern "C" void _s800D7C20_25();

struct NghResFile {
    void CopyDefaultNghToCache();
};

void NghResFile::CopyDefaultNghToCache() {
}
