// 0x80211660 InteractorModule::GetCursorIntersectionObjects(vector<short, (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); addi 30,1,8; li 0,0; stw 0,0x4(30); mr 31,3; stw 0,0x8(1); mr 29,4; li 0,1; mr 3,30; stw 0,0x8(30); mr 26,30; bl _s80211660_0; lis 9,-32697; mr 4,29; lwz 11,0x5e94(9); mr 5,30; lwz 3,0x4(11); bl _s80211660_1; lwz 0,0x8(1); cmpwi 0,0; bne 0f; lwz 0,0x0(31); mr 3,26; stw 0,0x4(31); bl _s80211660_2; b 15f; 0:; lwz 0,0x0(31); mr 3,26; stw 0,0x4(31); bl _s80211660_3; mr 4,3; mr 3,31; bl _s80211660_4; lwz 27,0x8(1); cmpwi 27,0; beq 14f; 1:; lwz 3,0x0(27); bl _s80211660_5; lwz 9,0x4(3); lha 0,0x328(9); lwz 9,0x32c(9); add 3,3,0; mtspr 8,9; blrl; lwz 30,0x4(31); lwz 0,0xc(31); sth 3,0x18(1); cmpw 30,0; beq 2f; sth 3,0x0(30); lwz 9,0x4(31); addi 9,9,2; stw 9,0x4(31); b 13f; 2:; lwz 0,0x0(31); li 9,1; stw 9,0x20(1); addi 10,1,32; subf 0,0,30; addi 11,1,28; srawi 9,0,1; stw 9,0x1c(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; add 0,0,0; mr 28,0; cmplwi 0,128; ble 4f; mr 3,28; bl _s80211660_6; mr 29,3; b 6f; 4:; mr 3,28; bl _s80211660_7; mr 29,3; b 6f; 5:; li 29,0; li 28,0; 6:; lwz 4,0x0(31); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80211660_8; add 0,3,30; b 8f; 7:; mr 0,29; 8:; lwz 9,0x20(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 10f; 9:; lhz 0,0x18(1); sth 0,0x0(30); addi 30,30,2; bdnz 9b; 10:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,1; beq 12f; add 4,0,0; cmplwi 4,128; ble 11f; bl _s80211660_9; b 12f; 11:; bl _s80211660_10; 12:; add 0,28,29; stw 29,0x0(31); stw 30,0x4(31); stw 0,0xc(31); 13:; lwz 27,0x8(27); cmpwi 27,0; bne 1b; 14:; mr 3,26; bl _s80211660_11; 15:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s80211660_0();
extern "C" void _s80211660_1();
extern "C" void _s80211660_2();
extern "C" void _s80211660_3();
extern "C" void _s80211660_4();
extern "C" void _s80211660_5();
extern "C" void _s80211660_6();
extern "C" void _s80211660_7();
extern "C" void _s80211660_8();
extern "C" void _s80211660_9();
extern "C" void _s80211660_10();
extern "C" void _s80211660_11();
extern "C" void f_80211660() {}
