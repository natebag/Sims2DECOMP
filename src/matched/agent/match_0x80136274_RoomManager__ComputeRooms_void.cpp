// 0x80136274 RoomManager::ComputeRooms(void) (784 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stfd f31,0x58(1); stmw 23,0x34(1); stw 0,0x64(1); stw 12,0x30(1); lwz 0,-31668(13); mr 26,3; cmpwi 0,0; bne 0f; addi 3,13,-24088; bl _s80136274_0; li 0,1; stw 0,-31668(13); 0:; lwz 0,0x24(26); cmpwi 0,0; bne 1f; mr 3,26; bl _s80136274_1; li 0,1; stw 0,0x24(26); 1:; lwz 9,0x4(26); li 24,0; lwz 28,0x8(9); stw 9,0x8(1); cmpw 28,9; beq 7f; li 23,1; 2:; lwz 31,0x14(28); cmpwi 31,0; beq 6f; lwz 0,0x34(31); mcrf cr4,cr0; cmpwi 0,0; beq 5f; lwz 0,0x84(31); cmpwi 0,0; beq 5f; mr 3,31; addi 27,31,4; bl _s80136274_2; fmr f31,f1; mr 3,31; bl _s80136274_3; li 9,0; stw 23,0x34(31); stw 9,0x84(31); lwz 30,0x4(31); lwz 0,0x4(27); cmpw 30,0; beq 4f; stw 9,0x94(31); lwz 0,0x4(27); cmpw 30,0; beq 4f; addi 29,1,32; addi 25,1,16; 3:; mr 4,30; mr 3,31; bl _s80136274_4; mr 4,30; addi 3,1,16; li 5,0; addi 30,30,3; bl _s80136274_5; lwz 11,0x10(1); mr 3,31; lwz 0,0x8(25); mr 4,29; lwz 9,0x4(25); stw 11,0x20(1); stw 0,0x8(29); stw 9,0x4(29); bl _s80136274_6; lwz 0,0x4(27); cmpw 30,0; bne 3b; 4:; mr 3,31; bl _s80136274_7; mr 3,31; bl _s80136274_8; fcmpu 0,f31,f1; beq 5f; lhz 4,0x0(31); li 3,237; bl _s80136274_9; 5:; beq cr4,6f; lwz 0,0x34(31); cmpwi 0,0; beq 6f; mr 3,31; bl _s80136274_10; cmpwi 3,0; bne 6f; mr 3,31; bl _s80136274_11; add 24,24,3; 6:; mr 3,28; bl _s80136274_12; lwz 0,0x4(26); mr 28,3; cmpw 28,0; stw 0,0x8(1); bne 2b; 7:; lis 9,-32706; lwz 11,0x4(26); lfs f0,-11492(9); extsh 30,24; stfs f0,0x2c(26); lwz 28,0x8(11); stw 11,0x8(1); cmpw 28,11; beq 10f; 8:; lwz 31,0x14(28); cmpwi 31,0; beq 9f; lwz 0,0x34(31); cmpwi 0,0; beq 9f; mr 3,31; bl _s80136274_13; cmpwi 3,0; beq 9f; lfs f13,0x7c(31); lfs f0,0x2c(26); fadds f0,f0,f13; stfs f0,0x2c(26); 9:; mr 3,28; bl _s80136274_14; lwz 0,0x4(26); mr 28,3; cmpw 28,0; stw 0,0x8(1); bne 8b; 10:; lfs f13,-24040(13); lfs f0,0x2c(26); lwz 11,-21496(13); fdivs f0,f0,f13; stfs f0,0x28(26); lwz 9,0x0(11); lha 3,0xf0(9); lwz 0,0xf4(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,1; beq 14f; bgt 11f; cmpwi 3,0; beq 12f; b 16f; 11:; cmpwi 3,2; beq 13f; cmpwi 3,3; beq 14f; b 16f; 12:; lfs f0,0x28(26); lfs f13,-24036(13); b 15f; 13:; lfs f0,0x28(26); lfs f13,-24028(13); b 15f; 14:; lfs f0,0x28(26); lfs f13,-24032(13); 15:; fadds f0,f0,f13; stfs f0,0x28(26); 16:; lis 9,-32706; lfs f0,0x28(26); lfs f13,-11488(9); fcmpu 0,f0,f13; blt 17f; lis 9,-32706; lfs f13,-11484(9); fcmpu 0,f0,f13; ble 18f; 17:; stfs f13,0x28(26); 18:; lwz 11,-21496(13); mr 5,30; li 4,27; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x20(26); lwz 0,0x64(1); lwz 12,0x30(1); mtspr 8,0; lmw 23,0x34(1); lfd f31,0x58(1); mtcrf 8,12; addi 1,1,96"
extern "C" void _s80136274_0();
extern "C" void _s80136274_1();
extern "C" void _s80136274_2();
extern "C" void _s80136274_3();
extern "C" void _s80136274_4();
extern "C" void _s80136274_5();
extern "C" void _s80136274_6();
extern "C" void _s80136274_7();
extern "C" void _s80136274_8();
extern "C" void _s80136274_9();
extern "C" void _s80136274_10();
extern "C" void _s80136274_11();
extern "C" void _s80136274_12();
extern "C" void _s80136274_13();
extern "C" void _s80136274_14();
extern "C" void f_80136274() {}
