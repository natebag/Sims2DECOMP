// 0x80013D4C AwarenessManager::PassiveInfluenceAwarenessCheck(unsigned (732 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lwz 9,-21488(13); mr 31,3; mr 27,4; lwz 11,0x0(9); lha 3,0xe0(11); lwz 0,0xe4(11); add 3,9,3; mtspr 8,0; blrl; mr. 28,3; beq 10f; lwz 9,0x34(31); lwz 10,0x0(9); lwz 11,0x4(10); lwz 0,0x344(11); lha 3,0x340(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x34(31); lwz 0,0x4(3); lwz 11,0x0(9); srawi 29,0,4; lwz 9,0x4(11); lwz 0,0x344(9); lha 3,0x340(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x0(3); cmpwi 29,0; srawi 30,0,4; blt 0f; lwz 3,-21488(13); lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; 0:; cmpwi 30,0; blt 1f; lwz 3,-21488(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; 1:; lwz 4,0x34(31); mr 5,29; mr 3,28; mr 6,30; bl _s80013D4C_0; mr 29,3; cmpwi 27,16; beq 12f; cmpwi 29,0; beq 9f; lwz 0,0x1c(29); lbz 28,0x1a(29); cmpwi 0,0; stw 0,0x8(1); bne 3f; mr 3,31; extsb 4,28; addi 5,1,8; bl _s80013D4C_1; cmpwi 28,4; bne 3f; lwz 30,0x8(1); cmpwi 30,0; beq 3f; lwz 3,0x8(31); li 4,512; bl _s80013D4C_2; lwz 0,0x0(30); cmpw 0,3; bne 2f; lwz 3,0x8(31); li 4,512; bl _s80013D4C_3; cmpwi 3,0; beq 3f; mr 3,31; bl _s80013D4C_4; b 12f; 2:; lfs f0,0x3c(31); lis 9,-32707; lfs f13,-26800(13); lfs f12,-8928(9); fadds f0,f0,f13; fcmpu 0,f0,f12; stfs f0,0x3c(31); blt 12f; 3:; cmplwi 28,1; ble 4f; lwz 3,0x34(31); lwz 9,0x4(3); lha 0,0x178(9); lwz 9,0x17c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 4f; lwz 3,0x4(31); bl _s80013D4C_5; cmpwi 3,0; bne 4f; lwz 0,0x0(31); andi. 9,0,64; beq 6f; lwz 0,0x8(1); mr 4,0; cmpwi 0,0; beq 5f; lwz 0,0x40(31); cmpw 0,4; beq 5f; 4:; mr 3,31; bl _s80013D4C_6; b 7f; 5:; mr 3,31; bl _s80013D4C_7; b 7f; 6:; lwz 0,0x8(1); mr 3,31; mr 4,0; stw 0,0x40(31); bl _s80013D4C_8; 7:; lwz 0,0x1c(31); cmpwi 0,0; beq 8f; lwz 9,0x0(29); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,29,3; blrl; lwz 0,0x1c(31); cmpw 0,3; beq 11f; 8:; lwz 9,0x0(29); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,29,3; blrl; lwz 0,0x0(31); li 9,1; stw 3,0x1c(31); ori 0,0,128; stw 9,0x18(31); rlwinm 0,0,0,21,19; stw 0,0x0(31); b 11f; 9:; mr 3,31; bl _s80013D4C_9; b 11f; 10:; mr 3,31; bl _s80013D4C_10; 11:; lwz 4,0x1c(31); cmpwi 4,0; beq 12f; lwz 0,0x0(31); andi. 9,0,128; beq 12f; lwz 3,-21484(13); bl _s80013D4C_11; cmpwi 3,0; bne 12f; mr 3,31; bl _s80013D4C_12; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80013D4C_0();
extern "C" void _s80013D4C_1();
extern "C" void _s80013D4C_2();
extern "C" void _s80013D4C_3();
extern "C" void _s80013D4C_4();
extern "C" void _s80013D4C_5();
extern "C" void _s80013D4C_6();
extern "C" void _s80013D4C_7();
extern "C" void _s80013D4C_8();
extern "C" void _s80013D4C_9();
extern "C" void _s80013D4C_10();
extern "C" void _s80013D4C_11();
extern "C" void _s80013D4C_12();
extern "C" void f_80013D4C() {}
