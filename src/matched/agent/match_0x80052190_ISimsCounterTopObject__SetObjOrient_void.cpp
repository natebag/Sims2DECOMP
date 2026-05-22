// 0x80052190 ISimsCounterTopObject::SetObjOrient(void) (948 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); mr 29,3; lwz 4,0x4(29); cmpwi 4,0; beq 0f; lwz 9,0x0(29); lha 3,0x190(9); lwz 0,0x194(9); add 3,29,3; mtspr 8,0; blrl; 0:; addi 30,29,1104; lwz 9,0x4(30); mr 26,30; b 3f; 1:; lwz 0,0x8(30); lwz 11,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 2f; lwz 9,0x0(11); lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr 9,31; 3:; li 0,1; cmpwi 9,0; bne 4f; li 0,0; 4:; cmpwi 0,0; bne 1b; mr 3,30; bl _s80052190_0; lwz 31,0x328(29); lwz 9,0x4(31); lwz 0,0x524(9); lha 3,0x520(9); mtspr 8,0; add 3,31,3; blrl; li 4,0; addi 3,3,40; bl _s80052190_1; lwz 9,0x4(31); lha 30,0x0(3); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc0(3); li 0,0; lwz 9,0x0(9); cmpwi 9,0; beq 5f; lwz 0,-4(9); 5:; cmpw 30,0; blt 6f; li 30,0; 6:; lwz 9,0x4(31); li 27,0; lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,0xc0(3); rlwinm 10,30,5,0,26; lis 3,-32697; lwz 9,0x0(11); addi 3,3,24012; lwzx 28,9,10; bl _s80052190_2; lwz 9,0x4(31); mr 30,3; lha 3,0x310(9); lwz 0,0x314(9); add 3,31,3; mtspr 8,0; blrl; lwz 11,0xc0(3); li 8,0; lwz 30,0x0(30); lwz 9,0x0(11); cmpwi 7,30,0; mr 10,30; lwz 9,0x0(9); b 8f; 7:; mr 11,10; lwz 0,0x0(11); cmpw 0,9; beq 12f; addi 10,11,16; addi 8,8,1; 8:; li 0,0; beq cr7,9f; lwz 0,-4(30); 9:; cmpw 8,0; blt 7b; 10:; lwz 9,0x4(31); addi 3,1,8; lha 4,0x358(9); lwz 0,0x35c(9); add 4,31,4; mtspr 8,0; blrl; addi 3,1,8; bl _s80052190_3; cmpwi 3,0; blt 11f; addi 3,1,8; bl _s80052190_4; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; cmpw 30,3; bgt 11f; addi 3,1,8; bl _s80052190_5; cmpwi 3,0; blt 11f; addi 3,1,8; bl _s80052190_6; lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; cmpw 30,3; ble 13f; 11:; mr 3,29; bl _s80052190_7; addi 3,1,8; li 4,2; bl _s80052190_8; b 18f; 12:; mr 27,10; b 10b; 13:; li 0,0; cmpwi 0,0; bne 16f; addi 3,1,16; addi 4,1,8; li 5,0; bl _s80052190_9; lwz 0,0x14(1); cmpwi 0,0; beq 17f; lis 9,-32763; addi 25,9,-6384; 14:; lwz 31,0x14(1); mr 3,31; bl _s80052190_10; cmpwi 3,0; bne 15f; addi 3,1,16; bl _s80052190_11; lwz 0,0x14(1); cmpwi 0,0; bne 14b; b 17f; 15:; bl _s80052190_12; li 6,0; li 7,0; li 4,1216; li 5,16; bl _s80052190_13; mr 30,3; li 5,1216; li 4,0; bl _s80052190_14; mr 3,30; bl _s80052190_15; lwz 0,0x3c8(29); mr 30,3; mr 4,31; stw 0,0x3c8(30); bl _s80052190_16; stw 31,0x28(30); mr 3,30; stw 25,0x1c(30); lwz 4,0x4(27); bl _s80052190_17; lwz 9,0x0(30); lwz 0,0x1e4(9); lha 3,0x1e0(9); mtspr 8,0; add 3,30,3; blrl; mr 4,30; mr 3,26; bl _s80052190_18; lwz 0,0x3cc(30); oris 0,0,4096; stw 0,0x3cc(30); lwz 4,0x4(29); cmpwi 4,0; beq 16f; lwz 9,0x0(29); lha 3,0x188(9); lwz 0,0x18c(9); add 3,29,3; mtspr 8,0; blrl; 16:; lwz 28,0x8(27); 17:; mr 4,28; mr 3,29; bl _s80052190_19; mr 3,29; bl _s80052190_20; lwz 9,0x0(29); lha 3,0x50(9); lwz 0,0x54(9); add 3,29,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s80052190_21; 18:; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s80052190_0();
extern "C" void _s80052190_1();
extern "C" void _s80052190_2();
extern "C" void _s80052190_3();
extern "C" void _s80052190_4();
extern "C" void _s80052190_5();
extern "C" void _s80052190_6();
extern "C" void _s80052190_7();
extern "C" void _s80052190_8();
extern "C" void _s80052190_9();
extern "C" void _s80052190_10();
extern "C" void _s80052190_11();
extern "C" void _s80052190_12();
extern "C" void _s80052190_13();
extern "C" void _s80052190_14();
extern "C" void _s80052190_15();
extern "C" void _s80052190_16();
extern "C" void _s80052190_17();
extern "C" void _s80052190_18();
extern "C" void _s80052190_19();
extern "C" void _s80052190_20();
extern "C" void _s80052190_21();
extern "C" void f_80052190() {}
