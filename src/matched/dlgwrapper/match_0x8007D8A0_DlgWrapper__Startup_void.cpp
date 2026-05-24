// 0x8007D8A0 DlgWrapper::Startup(void) (1272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f31,0x58(1); stmw 21,0x2c(1); stw 0,0x64(1); mr 28,3; mr 4,28; bl _s8007D8A0_0; lis 3,-32697; addi 3,3,24012; bl _s8007D8A0_1; mr 4,3; li 6,0; lis 3,-32692; li 5,0; addi 3,3,-30916; bl _s8007D8A0_2; mr 0,3; li 9,5; stw 0,0xa8(28); li 3,104; stw 0,-21408(13); stw 9,-21404(13); stw 9,-21400(13); bl _s8007D8A0_3; lwz 0,0xa4(28); mr 30,3; li 11,0; cmpwi 0,0; beq 0f; li 11,1; 0:; lis 9,-32698; li 0,0; addi 9,9,-12072; stw 0,0x0(30); stw 9,0x5c(30); addi 27,30,8; stw 0,0x4(30); addi 29,11,2; stw 0,0x8(30); addi 9,27,8; stw 0,0x4(27); cmpwi 29,0; stw 0,0x4(9); beq 2f; rlwinm 0,29,2,0,29; mr 31,0; cmplwi 0,128; ble 1f; mr 3,31; bl _s8007D8A0_4; b 3f; 1:; mr 3,31; bl _s8007D8A0_5; b 3f; 2:; li 3,0; li 31,0; 3:; add 0,3,31; li 9,0; stw 0,0xc(27); mr 11,3; stw 9,0x18(1); mr. 0,29; addi 9,1,24; stw 3,0x0(27); mtspr 9,0; stw 3,0x4(27); addi 10,30,28; addi 8,30,36; addi 24,1,8; addi 22,28,188; addi 23,1,16; addi 21,28,196; beq 5f; 4:; lwz 0,0x0(9); stw 0,0x0(11); addi 11,11,4; bdnz 4b; 5:; stw 11,0x4(27); lis 9,-32707; li 27,0; mr 3,30; lfs f31,0x6974(9); stw 27,0x18(30); lis 9,-32707; lwz 29,0x6978(9); stfs f31,0x1c(30); stfs f31,0x4(10); stw 29,0x24(30); stw 29,0x4(8); stw 29,0x2c(30); stw 29,0x30(30); stw 27,0x34(30); stw 27,0x38(30); stw 27,0x3c(30); bl _s8007D8A0_6; lis 9,-32698; mr 3,30; addi 9,9,-12136; stw 27,0x60(30); stw 9,0x5c(30); stw 27,0x64(30); bl _s8007D8A0_7; lis 9,-32698; mr 3,30; addi 9,9,-12456; stw 9,0x5c(30); bl _s8007D8A0_8; stw 30,0xac(28); mr 4,30; mr 3,28; bl _s8007D8A0_9; lwz 0,0xa4(28); cmpwi 0,0; beq 18f; li 3,52; li 26,1; bl _s8007D8A0_10; lis 11,-32698; mr 31,3; li 0,3; addi 11,11,-12008; stw 0,0x0(31); addi 9,31,32; stw 29,0x20(31); addi 25,1,28; stfs f31,0x18(31); stw 11,0x1c(31); stw 26,0x4(31); stw 27,0x8(31); stfs f31,0xc(31); stfs f31,0x10(31); stfs f31,0x14(31); stw 29,0x8(9); stw 29,0x4(9); stw 29,0x2c(31); stw 27,0x30(31); bl _s8007D8A0_11; lwz 9,0xac(28); stw 26,0x4(31); stw 31,0xb0(28); addi 29,9,8; stw 31,0x1c(1); lwz 30,0x4(29); lwz 0,0xc(29); cmpw 30,0; beq 6f; stw 31,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 17f; 6:; lwz 0,0x8(9); addi 10,1,36; stw 26,0x24(1); addi 11,1,32; subf 0,0,30; srawi 9,0,2; stw 9,0x20(1); cmplwi 9,1; bge 7f; mr 11,10; 7:; lwz 0,0x0(11); add. 0,9,0; beq 9f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 8f; mr 3,27; bl _s8007D8A0_12; mr 31,3; b 10f; 8:; mr 3,27; bl _s8007D8A0_13; mr 31,3; b 10f; 9:; li 31,0; li 27,0; 10:; lwz 4,0x0(29); cmpw 30,4; beq 11f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8007D8A0_14; add 0,3,30; b 12f; 11:; mr 0,31; 12:; lwz 9,0x24(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 14f; 13:; lwz 0,0x0(25); stw 0,0x0(30); addi 30,30,4; bdnz 13b; 14:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 16f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 15f; bl _s8007D8A0_15; b 16f; 15:; bl _s8007D8A0_16; 16:; add 0,27,31; stw 31,0x0(29); stw 0,0xc(29); stw 30,0x4(29); 17:; lwz 9,0xb0(28); lwz 0,0x4(9); ori 0,0,8; stw 0,0x4(9); 18:; lwz 11,0xac(28); lis 9,-32707; lfs f0,0x697c(9); lwz 30,0x60(11); addi 9,30,32; mr 3,9; stfs f0,0x34(9); bl _s8007D8A0_17; lwz 0,0x4(30); lis 9,-32707; lfs f0,0x6980(9); ori 0,0,2; stw 0,0x4(30); lwz 9,0xac(28); lwz 30,0x64(9); addi 11,30,32; mr 3,11; stfs f0,0x34(11); bl _s8007D8A0_18; lwz 0,0x4(30); lis 9,-32707; lis 11,-32707; lfs f12,0x6984(9); ori 0,0,2; lfs f13,0x6988(11); stw 0,0x4(30); lis 9,-32707; lfs f0,0x698c(9); lwz 11,0xac(28); lwz 9,0x64(11); addi 9,9,32; lwz 0,0x38(9); rlwinm 0,0,0,29,27; stw 0,0x38(9); lwz 11,0xac(28); lwz 9,0x64(11); addi 9,9,32; lwz 0,0x38(9); rlwinm 0,0,0,27,25; stw 0,0x38(9); stfs f12,0x8(1); stfs f13,0x4(24); lwz 9,0x4(24); stfs f0,0x10(1); lwz 0,0x8(1); stfs f0,0x4(23); stw 0,0xbc(28); lwz 10,0x10(1); stw 9,0x4(22); lwz 0,0x14(1); stw 10,0xc4(28); stw 0,0x4(21); lwz 11,0xac(28); lwz 9,0x64(11); addi 3,9,32; stw 10,0x2c(9); stw 0,0x30(9); bl _s8007D8A0_19; lwz 11,0xac(28); lis 9,-32707; lfs f13,0x6990(9); lwz 10,0x64(11); lfs f0,0x10(1); lwz 9,0x1c(10); lfs f1,0x8(1); lwz 0,0x4c(9); lha 3,0x48(9); fmadds f1,f0,f13,f1; mtspr 8,0; add 3,10,3; blrl; lwz 11,0xac(28); lis 9,-32707; lfs f0,0x6994(9); lwz 10,0x64(11); lfs f1,0xc(1); lwz 9,0x1c(10); fadds f1,f1,f0; lha 3,0x58(9); lwz 0,0x5c(9); add 3,10,3; mtspr 8,0; blrl; lwz 31,0xac(28); lis 9,-32707; addi 3,9,26988; stw 3,0x38(31); cmpwi 3,0; beq 19f; bl _s8007D8A0_20; 19:; stw 3,0x3c(31); li 0,0; stw 0,0xb4(28); stw 0,0xcc(28); lwz 0,0x64(1); mtspr 8,0; lmw 21,0x2c(1); lfd f31,0x58(1); addi 1,1,96"

extern "C" void _s8007D8A0_0();
extern "C" void _s8007D8A0_1();
extern "C" void _s8007D8A0_2();
extern "C" void _s8007D8A0_3();
extern "C" void _s8007D8A0_4();
extern "C" void _s8007D8A0_5();
extern "C" void _s8007D8A0_6();
extern "C" void _s8007D8A0_7();
extern "C" void _s8007D8A0_8();
extern "C" void _s8007D8A0_9();
extern "C" void _s8007D8A0_10();
extern "C" void _s8007D8A0_11();
extern "C" void _s8007D8A0_12();
extern "C" void _s8007D8A0_13();
extern "C" void _s8007D8A0_14();
extern "C" void _s8007D8A0_15();
extern "C" void _s8007D8A0_16();
extern "C" void _s8007D8A0_17();
extern "C" void _s8007D8A0_18();
extern "C" void _s8007D8A0_19();
extern "C" void _s8007D8A0_20();

struct DlgWrapper {
    void Startup();
};

void DlgWrapper::Startup() {
}
