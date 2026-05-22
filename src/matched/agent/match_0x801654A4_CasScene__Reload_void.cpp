// 0x801654A4 CasScene::Reload(void) (820 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-288(1); mfspr 0,8; stfd f31,0x118(1); stmw 25,0xfc(1); stw 0,0x124(1); mr 30,3; lwz 9,0x4(30); lha 3,0x98(9); lwz 0,0x9c(9); add 3,30,3; mtspr 8,0; blrl; mr 25,3; lwz 3,0xa80(30); cmpwi 3,0; beq 0f; bl _s801654A4_0; li 0,0; stw 0,0xa80(30); 0:; lwz 3,0xa84(30); cmpwi 3,0; beq 1f; bl _s801654A4_1; li 0,0; stw 0,0xa84(30); 1:; lwz 3,0xa88(30); cmpwi 3,0; beq 2f; li 4,3; bl _s801654A4_2; 2:; li 31,0; lis 3,-32696; stw 31,0xa88(30); lis 4,-27482; addi 3,3,32332; ori 4,4,26543; li 5,0; li 6,0; bl _s801654A4_3; stw 3,0xa80(30); cmpwi 3,0; beq 3f; lwz 11,-26512(13); lis 9,-32706; lfs f0,-980(9); stw 3,0x30(11); lwz 9,0xa80(30); addis 9,9,3; stw 31,-7084(9); lwz 11,0xa80(30); addis 11,11,3; stw 31,-7080(11); lwz 9,0xa80(30); addis 9,9,3; stfs f0,-7076(9); lwz 3,0xa80(30); bl _s801654A4_4; lwz 3,0xa80(30); bl _s801654A4_5; lwz 3,0xa80(30); li 4,1; bl _s801654A4_6; 3:; lis 9,-32702; li 31,0; addi 29,9,17904; lis 27,-32706; addi 26,1,72; li 28,0; 4:; lwz 7,0x0(29); li 4,64; addi 5,27,-988; mr 6,25; addi 3,1,8; addi 29,29,4; crxor 6,6,6; bl _s801654A4_7; mr 5,31; stb 28,0x47(1); mr 3,30; addi 4,1,8; bl _s801654A4_8; addi 31,31,1; cmpwi 31,3; ble 4b; lis 3,-32692; lis 4,-13677; addi 3,3,-27556; ori 4,4,30936; li 5,0; li 6,0; bl _s801654A4_9; li 0,4; stw 3,0xa84(30); mtspr 9,0; 5:; bdnz 5b; li 0,4; lwz 9,0x4(30); mtspr 9,0; 6:; bdnz 6b; lha 3,0x90(9); mr 5,26; lwz 0,0x94(9); li 4,0; add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 10f; li 3,76; bl _s801654A4_10; bl _s801654A4_11; mr 0,3; li 4,4; stw 0,0xa88(30); bl _s801654A4_12; lwz 3,0xa88(30); lis 4,-21665; ori 4,4,56524; bl _s801654A4_13; lfs f7,0x48(1); lis 9,-32706; lfs f11,0x4c(1); lfs f12,0x58(1); lfs f10,0x60(1); lfs f9,0x64(1); fsubs f12,f12,f11; lfs f0,0x54(1); fsubs f10,f10,f7; fsubs f9,f9,f11; lfs f6,0x50(1); lfs f8,0x68(1); fsubs f0,f0,f7; fmuls f11,f12,f10; lfs f13,0x5c(1); fsubs f8,f8,f6; stfs f0,0xa8(1); fmsubs f11,f0,f9,f11; lfs f7,-980(9); fsubs f13,f13,f6; stfs f12,0xac(1); fmuls f0,f0,f8; stfs f13,0xb0(1); fmsubs f0,f13,f10,f0; stfs f10,0xb8(1); fmuls f13,f13,f9; stfs f9,0xbc(1); fmsubs f12,f12,f8,f13; stfs f8,0xc0(1); stfs f0,0xcc(1); fcmpu 0,f12,f7; stfs f12,0xc8(1); stfs f11,0xd0(1); bne 7f; fcmpu 0,f0,f7; bne 7f; fcmpu 0,f11,f7; beq 8f; 7:; addi 3,1,200; mr 4,3; bl _s801654A4_14; 8:; lis 9,-32706; li 28,0; lfs f31,-976(9); addi 27,1,216; addi 29,1,120; addi 31,1,72; 9:; lfs f9,0xc8(1); mr 4,28; lfs f11,0xcc(1); mr 5,29; lfs f10,0xd0(1); fmuls f9,f9,f31; fmuls f11,f11,f31; stfs f9,0xe8(1); fmuls f10,f10,f31; stfs f11,0xec(1); stfs f10,0xf0(1); addi 28,28,1; addi 29,29,12; lfs f0,0x0(31); lfs f13,0x4(31); lfs f12,0x8(31); fadds f0,f0,f9; lwz 3,0xa88(30); fadds f13,f13,f11; fadds f12,f12,f10; stfs f0,0xd8(1); stfs f13,0xdc(1); stfs f12,0xe0(1); lwz 0,0xd8(1); lwz 9,0x4(27); lwz 11,0x8(27); stw 0,0x30(31); stw 9,0x34(31); stw 11,0x38(31); bl _s801654A4_15; addi 31,31,12; cmpwi 28,3; ble 9b; 10:; lwz 0,0x124(1); mtspr 8,0; lmw 25,0xfc(1); lfd f31,0x118(1); addi 1,1,288"
extern "C" void _s801654A4_0();
extern "C" void _s801654A4_1();
extern "C" void _s801654A4_2();
extern "C" void _s801654A4_3();
extern "C" void _s801654A4_4();
extern "C" void _s801654A4_5();
extern "C" void _s801654A4_6();
extern "C" void _s801654A4_7();
extern "C" void _s801654A4_8();
extern "C" void _s801654A4_9();
extern "C" void _s801654A4_10();
extern "C" void _s801654A4_11();
extern "C" void _s801654A4_12();
extern "C" void _s801654A4_13();
extern "C" void _s801654A4_14();
extern "C" void _s801654A4_15();
extern "C" void f_801654A4() {}
