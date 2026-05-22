// 0x8020AAF0 InteractorModule::InteractorInputManager::InstanceData::Update(float) (716 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f30,0x28(1); stfd f31,0x30(1); stmw 24,0x8(1); stw 0,0x3c(1); mr 27,3; fmr f30,f1; lwz 0,0x1c(27); cmpwi 0,0; beq 11f; lwz 3,-26524(13); lis 24,-32704; lwz 4,0x18(27); bl _s8020AAF0_0; lwz 25,0x0(27); mr 26,3; lwz 0,0x4(27); cmpw 25,0; beq 8f; 0:; lwz 0,0x4(25); lwz 31,0x8(25); cmpwi 0,0; lwz 28,0x0(25); beq 5f; srawi 30,31,16; rlwinm 29,31,0,16,31; lwz 6,0x14(27); mr 3,26; mr 4,30; mr 5,29; bl _s8020AAF0_1; lwz 6,0x14(27); fmr f31,f1; mr 4,30; mr 5,29; mr 3,26; bl _s8020AAF0_2; lfs f13,-12028(24); fsubs f0,f31,f1; fabs f0,f0; fcmpu 0,f0,f13; ble 1f; fabs f0,f1; fcmpu 0,f0,f13; cror 3,2,0; bso 4f; fabs f0,f31; fcmpu 0,f0,f13; bgt 2f; lwz 3,0x1c(27); mr 4,28; lwz 9,0x5c(3); lha 0,0x60(9); lwz 9,0x64(9); b 3f; 1:; fabs f0,f1; fcmpu 0,f0,f13; ble 4f; 2:; lwz 3,0x1c(27); mr 4,28; lwz 9,0x5c(3); lha 0,0x70(9); lwz 9,0x74(9); 3:; add 3,3,0; mtspr 8,9; blrl; b 7f; 4:; lwz 3,0x1c(27); mr 4,28; lwz 9,0x5c(3); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; b 7f; 5:; lwz 30,0x14(27); mr 3,26; mr 4,30; bl _s8020AAF0_3; mr 29,3; mr 4,30; mr 3,26; bl _s8020AAF0_4; mr 6,3; mr 5,29; mr 3,26; mr 4,31; li 7,0; bl _s8020AAF0_5; cmpwi 3,0; beq 6f; lwz 10,0x1c(27); lis 11,-32704; mr 4,28; lfs f1,-12024(11); lwz 9,0x5c(10); lha 3,0x60(9); lwz 0,0x64(9); add 3,10,3; mtspr 8,0; blrl; b 7f; 6:; lwz 30,0x14(27); mr 3,26; mr 4,30; bl _s8020AAF0_6; mr 29,3; mr 4,30; mr 3,26; bl _s8020AAF0_7; mr 6,3; mr 4,31; mr 5,29; mr 3,26; li 7,0; bl _s8020AAF0_8; cmpwi 3,0; beq 7f; lwz 3,0x1c(27); mr 4,28; lwz 9,0x5c(3); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; 7:; lwz 0,0x4(27); addi 25,25,12; cmpw 25,0; bne 0b; 8:; lis 9,-32697; lwz 0,0x6174(9); cmpwi 0,0; bne 10f; lfs f1,-12028(24); mr 3,26; li 4,0; li 5,-1; bl _s8020AAF0_9; cmpwi 3,0; bne 9f; lfs f1,-12028(24); mr 3,26; li 4,1; li 5,-1; bl _s8020AAF0_10; cmpwi 3,0; bne 9f; li 4,-1; mr 3,26; bl _s8020AAF0_11; mr 4,3; li 5,0; mr 3,26; li 6,-1; bl _s8020AAF0_12; cmpwi 3,0; beq 10f; 9:; lwz 3,0x1c(27); lwz 9,0x5c(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; b 11f; 10:; lwz 9,0x1c(27); lfs f0,0x58(9); fadds f0,f0,f30; stfs f0,0x58(9); 11:; lwz 0,0x3c(1); mtspr 8,0; lmw 24,0x8(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s8020AAF0_0();
extern "C" void _s8020AAF0_1();
extern "C" void _s8020AAF0_2();
extern "C" void _s8020AAF0_3();
extern "C" void _s8020AAF0_4();
extern "C" void _s8020AAF0_5();
extern "C" void _s8020AAF0_6();
extern "C" void _s8020AAF0_7();
extern "C" void _s8020AAF0_8();
extern "C" void _s8020AAF0_9();
extern "C" void _s8020AAF0_10();
extern "C" void _s8020AAF0_11();
extern "C" void _s8020AAF0_12();
extern "C" void f_8020AAF0() {}
