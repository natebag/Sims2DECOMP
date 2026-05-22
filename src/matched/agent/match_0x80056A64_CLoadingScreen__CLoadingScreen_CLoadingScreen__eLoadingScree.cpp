// 0x80056A64 CLoadingScreen::CLoadingScreen(CLoadingScreen::eLoadingScreenMode) (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32698; mr 31,3; addi 9,9,-14056; mr 30,4; stw 9,0x390(31); bl _s80056A64_0; li 29,0; stw 30,0x354(31); lis 3,-32692; stw 29,0x350(31); lis 4,32602; stw 29,0x358(31); ori 4,4,48173; stw 29,0x35c(31); li 5,0; stw 29,0x360(31); li 6,0; stw 29,0x364(31); addi 3,3,-17444; stw 29,0x388(31); stw 29,0x38c(31); stw 29,-24944(13); bl _s80056A64_1; lis 30,-32692; stw 3,0x358(31); addi 30,30,-27556; lis 4,27935; ori 4,4,2390; li 5,0; li 6,0; mr 3,30; bl _s80056A64_2; stw 3,0x35c(31); lis 4,28588; li 5,0; li 6,0; ori 4,4,34431; mr 3,30; bl _s80056A64_3; stw 3,0x360(31); li 3,60; bl _s80056A64_4; bl _s80056A64_5; mr 0,3; lis 4,27935; stw 0,0x364(31); ori 4,4,2390; bl _s80056A64_6; lwz 9,0x364(31); lis 11,-32707; lfs f0,0x38e8(11); li 0,1; stw 29,0x20(9); addi 10,1,8; lis 9,-32707; li 5,0; lwz 11,0x364(31); addi 6,31,896; lfs f12,0x38ec(9); fmr f13,f0; stw 0,0x24(11); li 0,2; lwz 9,0x364(31); mtspr 9,0; stfs f0,0x18(9); stfs f0,0x8(1); stfs f0,0x4(10); stfs f0,0x8(10); lwz 0,0x4(10); lwz 11,0x364(31); lwz 8,0x8(1); lwz 7,0x8(10); addi 9,11,12; stw 8,0xc(11); stw 7,0x8(9); stw 0,0x4(9); 0:; stfs f13,-24(6); stw 5,-16(6); stfs f12,-8(6); stfs f13,0x0(6); addi 6,6,4; bdnz 0b; lwz 0,0x354(31); cmpwi 0,0; blt 1f; cmpwi 0,5; bgt 1f; li 0,1; stw 0,0x388(31); 1:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80056A64_0();
extern "C" void _s80056A64_1();
extern "C" void _s80056A64_2();
extern "C" void _s80056A64_3();
extern "C" void _s80056A64_4();
extern "C" void _s80056A64_5();
extern "C" void _s80056A64_6();
extern "C" void f_80056A64() {}
