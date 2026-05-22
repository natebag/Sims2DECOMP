// 0x80204838 InteractorModule::DirectInteractor::Update(float) (948 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 30,0x18(1); stw 0,0x2c(1); lwz 9,-21496(13); mr 31,3; fmr f31,f1; lwz 11,0x0(9); lha 3,0x78(11); lwz 0,0x7c(11); add 3,9,3; mtspr 8,0; blrl; cmpwi 3,0; bne 15f; lis 9,-32697; lwz 0,0x0(31); addi 9,9,24012; addi 30,9,188; rlwinm 0,0,2,0,29; lwzx 11,30,0; cmpwi 11,0; beq 1f; lwz 9,0x4(11); lha 3,0x358(9); lwz 0,0x35c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,1; bne 0f; lwz 0,0x0(31); rlwinm 0,0,2,0,29; lwzx 11,30,0; lwz 9,0x4(11); lha 3,0x378(9); lwz 0,0x37c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x0(31); rlwinm 0,0,2,0,29; lwzx 11,30,0; lwz 9,0x4(11); lha 3,0x348(9); lwz 0,0x34c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,1; bne 1f; lwz 0,0x0(31); rlwinm 0,0,2,0,29; lwzx 11,30,0; lwz 9,0x4(11); lha 3,0x370(9); lwz 0,0x374(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr 3,31; bl _s80204838_0; fmr f1,f31; mr 3,31; bl _s80204838_1; lis 9,-32697; lwz 0,0x0(31); addi 9,9,24012; rlwinm 0,0,2,0,29; addi 9,9,188; lwzx 11,9,0; cmpwi 11,0; stw 11,0x70(31); bne 2f; lwz 9,0x5c(31); lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; b 15f; 2:; lwz 3,-21496(13); li 4,30; lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 3f; lwz 9,0x5c(31); lha 3,0x80(9); lwz 0,0x84(9); add 3,31,3; mtspr 8,0; blrl; 3:; lwz 30,0x80(31); cmpwi 30,0; bne 4f; lis 9,-32704; lfs f13,0x58(31); lfs f0,-13564(9); fcmpu 0,f13,f0; ble 4f; lwz 11,0x70(31); lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; li 0,10; stw 0,0xb0(3); stw 30,0x64(31); 4:; lwz 0,0x68(31); cmpwi 0,0; bne 5f; mr 3,31; bl _s80204838_2; cmpwi 3,0; beq 15f; 5:; lwz 9,0x78(31); cmpwi 9,0; beq 6f; li 0,0; stw 0,0x1f8(9); 6:; mr 3,31; bl _s80204838_3; cmpwi 3,0; bne 13f; mr 3,31; bl _s80204838_4; cmpwi 3,0; beq 7f; mr 3,31; bl _s80204838_5; mr 3,31; bl _s80204838_6; 7:; lwz 30,0x6c(31); cmpwi 30,0; bne 13f; lis 9,-32704; lfs f13,0x58(31); lfs f0,-13564(9); fcmpu 0,f13,f0; cror 3,2,0; bns 13f; mr 3,31; bl _s80204838_7; lwz 0,0x64(31); cmpwi 0,1; beq 9f; bgt 8f; cmpwi 0,0; beq 11f; b 13f; 8:; cmpwi 0,2; bne 13f; stw 30,0x2c(31); addi 9,31,32; lwz 8,0x20(31); addi 11,31,8; lwz 10,0x8(9); mr 3,31; lwz 0,0x4(9); stw 8,0x8(31); stw 10,0x8(11); stw 0,0x4(11); bl _s80204838_8; b 13f; 9:; lwz 11,0x70(31); cmpwi 11,0; beq 10f; lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; addi 3,1,8; bl _s80204838_9; lwz 11,0x8(1); addi 9,31,8; lwz 10,0xc(1); lwz 0,0x10(1); stw 11,0x8(31); stw 0,0x8(9); stw 10,0x4(9); 10:; mr 3,31; bl _s80204838_10; mr 3,31; bl _s80204838_11; b 13f; 11:; lwz 11,0x70(31); cmpwi 11,0; beq 12f; lwz 9,0x4(11); lwz 0,0x18c(9); lha 3,0x188(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; addi 3,1,8; bl _s80204838_12; lwz 11,0x8(1); addi 9,31,8; lwz 10,0xc(1); lwz 0,0x10(1); stw 11,0x8(31); stw 0,0x8(9); stw 10,0x4(9); 12:; mr 3,31; bl _s80204838_13; 13:; lwz 3,0x0(31); bl _s80204838_14; cmpwi 3,0; beq 15f; lwz 0,0x30(31); cmpwi 0,0; beq 14f; mr 3,31; bl _s80204838_15; 14:; lwz 0,0x78(31); cmpwi 0,0; beq 15f; mr 3,31; bl _s80204838_16; 15:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s80204838_0();
extern "C" void _s80204838_1();
extern "C" void _s80204838_2();
extern "C" void _s80204838_3();
extern "C" void _s80204838_4();
extern "C" void _s80204838_5();
extern "C" void _s80204838_6();
extern "C" void _s80204838_7();
extern "C" void _s80204838_8();
extern "C" void _s80204838_9();
extern "C" void _s80204838_10();
extern "C" void _s80204838_11();
extern "C" void _s80204838_12();
extern "C" void _s80204838_13();
extern "C" void _s80204838_14();
extern "C" void _s80204838_15();
extern "C" void _s80204838_16();
extern "C" void f_80204838() {}
